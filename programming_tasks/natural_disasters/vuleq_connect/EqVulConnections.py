import folium
import csv
import numpy as np
from geopy.distance import geodesic
from scipy.spatial import KDTree
from haversine import haversine

m = folium.Map()
Buff_list1 = []
Buff_list2 = []
line_between_objects1 = []
line_between_objects2 = []
repeat_check1 = 0
repeat_check2 = 0
repeat_check11 = 0
repeat_check22 = 0

#Opening a CVS-file and processing it
with open("query vul.csv", encoding='utf-8', newline = '') as csvfile:
	reader1 = csv.DictReader(csvfile,delimiter=";")
	for row in reader1: 

		# Puy Pariou;Point(2.971484 45.796824) -> popup;point(Buff_list1)
		# Editing the original coordinates
		popup = row['volcanoLabel']
		cords = row['location'].replace("Point(", "")
		cords = cords.replace(")", "")
		Lat = cords.partition(' ')
		Buff_list1.extend([Lat[0], Lat[2]]) # Adding coordinates to buffer

		# Coordinate processing
		cor=tuple([float(i) for i in Buff_list1])
		Buff_list1.clear()
		if(repeat_check1 == cor[0] and repeat_check2 == cor[1]):
			continue
		line_between_objects1.append((cor[1], cor[0]))
		folium.Circle(radius=500, location=[cor[1], cor[0]], popup=popup, tooltip='Вулкан', color="red").add_to(m) # Drawing popups
		repeat_check1 = cor[0] 
		repeat_check2 = cor[1]

# The same function is only for earthquakes CVS-file 
with open("query eq.csv", encoding='utf-8',  newline = '') as csvfile:
	reader2 = csv.DictReader(csvfile,delimiter=";")
	for row in reader2:
		popup = row['earthquakeLabel']
		cords=row['location'].replace("Point(", "")
		cords=cords.replace(")", "")
		Lat = cords.partition(' ')
		Buff_list2.extend([Lat[0], Lat[2]])
		cor=tuple([float(i) for i in Buff_list2])
		Buff_list2.clear()
		if(repeat_check11 == cor[0] and repeat_check22 == cor[1]):
			continue
		line_between_objects2.append((cor[1], cor[0]))
		folium.Circle(radius=500, location=[cor[1], cor[0]], popup=popup, tooltip='Землетрясение', color="black").add_to(m)
		repeat_check11 = cor[0]
		repeat_check22 = cor[1]

# Drawing a line between two coordinates using K-Demension Trees 
	# The used algorithm is described in "Maneewongvatana and Mount" 1999. 
	# The general idea is that the  is a binary tree, each of whose nodes represents an axis-aligned hyperrectangle. 
	# Each node specifies an axis and splits the set of points based on whether their coordinate along that axis is greater than or less than a particular value.
tree1 = KDTree(line_between_objects1) # Creating KDTree with the values of our coordinates
dist = 63 # Minimal distance for creating a line (63 the maximum distance at which an earthquake affects a volcano)
closest_points = tree1.query(line_between_objects2, k=1, distance_upper_bound=dist)[1]
closest_pairs = np.array([(line_between_objects2[i], line_between_objects1[closest_points[i]]) for i in range(len(line_between_objects1))])
distance = tree1.query(line_between_objects2, k=1)[0]
closest_pairs_check_arrey = np.array([(line_between_objects2[i], line_between_objects1[closest_points[i]], distance[i]) for i in range(len(line_between_objects1))])
closest_pairs_with_distance_within_distance = np.array([(line_between_objects2[i], line_between_objects1[closest_points[i]]) for i in range(len(line_between_objects1)) if haversine(line_between_objects2[i], line_between_objects1[closest_points[i]]) <= dist])

#Drawing lines
for pair in closest_pairs_with_distance_within_distance:
 	folium.PolyLine(pair, color="purple", weight=1, opacity=1).add_to(m)

# Saving the map
m.save('Fullmap.html')
