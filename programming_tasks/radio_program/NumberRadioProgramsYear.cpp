#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int StrToInt(string b)
{
	int l, M;
	l = b.length();
	M = 0;
	for (int i = 0; i < l; i++)
	{
		M += (b[i] - '0') * pow(10, l - i - 1);
	}
	return M;
}

fstream years("years.txt");
fstream countProgram("countProgram.txt");

int main() {

	//first radioProgramm in 1920 => countYears[0] - count of radio programs in 1920 years
	string strQuery = "2000-7n2010-4n1941-12n1992-24n1982-10n2006-5n1999-2n1989-26n1924-37n2004-12n1998-19n1983-2n2018-2n1968-1n1991-23n1973-35n1966-1n1976-5n1988-22n2002-4n1937-73n1966-18n1984-24n1998-3n2002-4n1941-18n1940-6n1984-13n1952-58n2004-3n1960-1n1964-1n1942-20n1976-33n1937-23n1940-6n1988-19n1967-47n2008-12n2009-7n1969-1n2001-12n2003-2n1983-20n1945-25n2002-9n1998-16n1961-31n1985-3n2000-12n2007-4n1965-1n1984-35n1981-7n1988-1n1975-11n1973-1n1995-12n1978-24n1974-38n1986-1n1976-13n1925-67n2006-2n1989-11n1972-1n1938-11n1962-1n1947-15n1970-19n1980-8n2008-5n1965-37n1970-29n1943-16n1990-14n1995-13n1980-4n1973-5n1920-81n1920-81n1972-17n1947-38n1947-68n1950-2n1974-43n1992-15n1955-4n2007-6n1987-18n1992-6n1992-6n1987-18n1957-1n1963-1n1974-37n1973-16n1989-26n2007-5n1966-10n1932-17n1997-7n1961-1n2006-3n1959-11n1965-4n2006-1n1950-10n1921-19n1998-4n1940-49n1984-21n2003-7n2007-6n1967-2n1970-1n2009-10n2002-9n1984-28n2002-8n1928-20n1951-12n2000-10n1987-18n2002-4n1967-4n2000-6n1971-1n2004-1n1954-42n1982-16n2021-1n2000-6n2009-10n1975-27n2010-1n1969-22n2011-6n2019-1n2017-1n2020-1n1957-22n1993-5n2006-6n2002-6n1960-24n1965-43n1977-5n2016-6n1997-3n2003-16n2020-3n1999-5n2011-11n1931-17n2018-1n1955-24n2011-10n1981-20n2017-5n1969-20n1995-19n1940-18n1974-24n2021-2n1995-10n1958-7n1962-58n1962-58n1992-13n1964-6n1987-21n1968-31n1989-3n1991-2n2019-2n2014-1n1969-2n1996-15n2019-1n1957-2n2020-1n1963-28n1979-42n1983-4n1929-3n2005-10n1983-3n1956-36n1941-5n";
	string strQueryYears = "193420121945194719951951197420041969201119512001200919571991196919871999199019461961200219992003199519811998200319871969199619961986200219972009196220101952198719671968195719951986199919722013194519891948200320031955199519882002195120071995200119361949199420091996199019331994200819561942196619952011197219501993200220001959200019772003198919971997193619941999197619711996200519922010199220021986196920081988200219782001201219811992199619991993201020071999199519931980193120051957192919621991200719461981198320092005193220111977197719671928200720041977198819252019200620081950196519982002199120081982200319511994200619632010200920041952201119811986197719652009201220072000199519741994201219631951196520122012197419562013199020101995199319922001199520012000193120122008192920132004200919951972201420152012201420111963201320131937201519261939201520152015201720171963201720182016201719792007198519852014201620171986199820171982201720072017201420161947201620152004198720142017201620042011201620192016194020171995201819921995199820061989199519952018201920201988201519962016199019922015197420151997201920202015201820181987201620182017201920191991200320162010201620051993201720112017201320112016200719872014201920192020201520202017199420182021202019772019201620082013198419832020200720141998202020202020201120202020194819312020201819642013196420182021202120212021202120211958202220221947202220221925201920212020194320211928201720212012202220202017";
	bool flagYear = true;

	int countYearsRadio[103];
	for (int i = 0; i < 103; i++) {
		countYearsRadio[i] = 0;
	}

	

	char n = 'n';

	string strOnlyYear = "";
	int differenceYear = 0;

	string yearStr = strQuery.substr(0, 4);
	string countYears;

	//Может быть что количество лет двузначное число (Но не трехзначное!)
	if (n == strQuery[6]) {
		countYears = strQuery.substr(5, 1);
	}
	else {
		countYears = strQuery.substr(5, 2);
		flagYear = false;
	}
	
	int value = 0;
	

	int difference = StrToInt(yearStr) - 1920;

	for (int j = 0; j < StrToInt(countYears); j++) {
		countYearsRadio[difference + j]++;
		//cout << countYearsRadio[difference + j] << endl;
	}

	//if (flagYear) {
	//	for (int j = 0; j < StrToInt(countYears); j++) {
	//		countYearsRadio[difference + j]++;
	//		//cout << countYearsRadio[difference + j] << endl;
	//	}
	//}
	//else {

	//}
	
	if (flagYear) {

		for (int i = 7; i < strQuery.size(); i += 7) {

			if (strQuery[i + 6] == n) {
				yearStr = strQuery.substr(0 + i, 4);
				countYears = strQuery.substr(5 + i, 1);

				difference = StrToInt(yearStr) - 1920;

				for (int j = 0; j < StrToInt(countYears); j++) {
					countYearsRadio[difference + j]++;
				}
			}
			else {
				yearStr = strQuery.substr(0 + i, 4);
				countYears = strQuery.substr(5 + i, 2);
				i++;
				difference = StrToInt(yearStr) - 1920;

				for (int j = 0; j < StrToInt(countYears); j++) {
					countYearsRadio[difference + j]++;
				}
			}
		}
	}
	else {
		for (int i = 8; i < strQuery.size(); i += 7) {

			if (strQuery[i + 6] == n) {
				yearStr = strQuery.substr(0 + i, 4);
				countYears = strQuery.substr(5 + i, 1);

				difference = StrToInt(yearStr) - 1920;

				for (int j = 0; j < StrToInt(countYears); j++) {
					countYearsRadio[difference + j]++;
				}
			}
			else {
				yearStr = strQuery.substr(0 + i, 4);
				countYears = strQuery.substr(5 + i, 2);
				i++;
				difference = StrToInt(yearStr) - 1920;

				for (int j = 0; j < StrToInt(countYears); j++) {
					countYearsRadio[difference + j]++;
				}
			}
		}
	}
	
	for (int l = 0; l < strQueryYears.size(); l += 4) {
		strOnlyYear = strQueryYears.substr(l, 4);
		differenceYear = 2022 - StrToInt(strOnlyYear);
		for (int i = StrToInt(strOnlyYear); i < 2023; i++) {
			countYearsRadio[i - 1920]++;
		}
	}
	

	for (int i = 0; i < 103; i++) {
		years << i + 1920 << endl;
		countProgram << countYearsRadio[i] << endl;;
		//cout << countYearsRadio[i] << " ";
		//cout << "Year of radio program: " << i + 1920 << " Count radio programs: " << countYearsRadio[i] << endl;
	}

	years.close();
	countProgram.close();
	return 0;
}
