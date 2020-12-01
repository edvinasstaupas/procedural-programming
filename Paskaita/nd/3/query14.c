#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	char name[30];
	char surname[30];
	int course;					// year of study
	double average; 			// average grade

	int load; 					// number of courses
	char courses[10][30]; 		// course names
	int grades[10]; 			// course grades

	char languages[100];		// spoken languages

} Student;

typedef struct course {
	char name[30];
	int studentCount;
} course;

int main(int argc, char *argv[]) {
	FILE *db = NULL;
	// open database file for reading, provide a parameter or use default "db.bin"
	if (argc > 1)
		db = fopen(argv[1], "rb");
	else
		db = fopen("db.bin", "rb");

	if (db){
		Student students[1000];			// all the data goes here
		int size = 0;					// how many students in database

		// reading data from file
		fread(&size, sizeof(int), 1, db);

		for (int i = 0; i < size; i++){
			fread(&students[i], sizeof(Student), 1, db);
		}
		printf("%d records loaded succesfully\n", size);


        course a[50];
        int m = 0;
        for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i];
            for (int i = 0; i < s.load; ++i){ // process each course taken by the student
                for(int j = 0; j < m; ++j){
                    int l = findcourse (s.courses[i], a[j].name, m);
                    if (l < 0){
                        strcpy(a[j].name, s.courses[i]);
                        ++a[j].studentCount;
                    } else {
                        ++a[l].studentCount;
                    }
                }
            }
		}


		// MODIFY CODE BELOW
		int counterDemo = 0; // for counting students
		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s
			if(1){ // *** first filter, conditions on the student
				printf("%s %s %d %f %d ", s.name, s.surname, s.course, s.average, s.load); // print student data
				int anotherDemo = 0; // for counting courses/grades
				for (int i = 0; i < s.load; ++i){ // process each course taken by the student
                    for(int j = 0; j < m; ++j){
                        int l = findcourse (s.courses[i], a[j].name, m);
                        if (a[l].studentCount != 1){
                            ++counterDemo;
                        }
                    }
                }
            }
		}
		printf("Filter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);
	} else {
		printf("File db.bin not found, check current folder\n");
	}

	return 0;
}

int findcourse (char course[], char name[], int n){
    for(int i = 0; i < n; ++i){
        if(strcmp(course, name))
            return i;
    }
    return -1;
}
