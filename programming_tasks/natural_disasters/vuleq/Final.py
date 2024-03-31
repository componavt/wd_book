import folium
import csv
m = folium.Map()
lst1 = []
lst2 = []
chck1 = 0
chck2 = 0
chck11 = 0
chck22 = 0

with open("query vul.csv", encoding='utf-8', newline = '') as csvfile:
	reader1 = csv.DictReader(csvfile,delimiter=";")
	for row in reader1:
		popup = row['volcanoLabel']
		cords=row['location'].replace("Point(", "")
		cords=cords.replace(")", "")
		Lat = cords.partition(' ')
		lst1.extend([Lat[0], Lat[2]])
		cor=tuple([float(i) for i in lst1])
		lst1.clear()
		if(chck1 == cor[0] and chck2 == cor[1]):
			continue
		folium.Circle(radius=500, location=[cor[1], cor[0]], popup=popup, tooltip='Вулкан', color="black").add_to(m)
		chck1 = cor[0]
		chck2 = cor[1]
with open("query eq.csv", encoding='utf-8',  newline = '') as csvfile:
	reader2 = csv.DictReader(csvfile,delimiter=";")
	for row in reader2:
		popup = row['earthquakeLabel']
		cords=row['location'].replace("Point(", "")
		cords=cords.replace(")", "")
		Lat = cords.partition(' ')
		lst2.extend([Lat[0], Lat[2]])
		cor=tuple([float(i) for i in lst2])
		lst2.clear()
		if(chck11 == cor[0] and chck22 == cor[1]):
			continue
		folium.Circle(radius=500, location=[cor[1], cor[0]], popup=popup, tooltip='Землетрясение', color="red").add_to(m)
		chck11 = cor[0]
		chck22 = cor[1]
m.save('Fullmap.html')
