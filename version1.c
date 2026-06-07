#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int rollno;
    char name[50];
    int age;
    float cgpa;
};


//to display all the students
void display(struct student *school, int last){
    for (int i=0; i<last+1; i++){
        printf("The roll number you entered is:\n");
        printf("Name: %s\n", school[i].name);
        printf("Age: %d\n", school[i].age);
        printf("Roll No: %d\n", school[i].rollno);
        printf("CGPA: %f\n", school[i].cgpa);
    }
}

//to search(using bianry search)
int search(struct student *school, int rn, int max){
    if (rn >= max) return -1;

    int low=0, high = 0, avg=0;
    high = max;

    while (low <= high){
        avg = (low+high)/2;
        if (rn == school[avg].rollno) return avg;
        else if (rn > school[avg].rollno) low = avg+1;
        else if (rn < school[avg].rollno) high = avg-1;
    }
    return -1;
}

int main(){
    //Mahindra is the name of the struct because I am currently a B.Tech student at Mahindra University ;]
    struct student* mahindra = (struct student*)malloc(20 * sizeof(struct student));
    
    int last = -1;

    //title
    for (int i=0; i<29; i++){
        printf("#");
    }
    printf("\n # STUDENT MANAGEMENT SYSTEM #\n");
    for (int i =0; i<29; i++){
        printf("#");
    }
    printf("\n");



    //choices you want to make 
    printf("1. Add Student\n2. View All Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Exit\n");


    //choice making
    int choice=0;
    char yaorne = 'y';
    
    while (yaorne == 'y'){
        //this will continue until you want it to 
        
                printf("What operation you want to do: ");
                scanf("%d", &choice);
                printf("\n");

            if (choice == 3){
                //search
                int num, rollnum;
                printf("Enter the Roll Number you want to search: ");
                scanf("%d", &num);
                printf("\n");

                rollnum = search(mahindra, num, last);
                if (rollnum == -1) printf("The roll number is not in the list.\n");
                else{
                    printf("The roll number you entered is:\n");
                    printf("Name: %s\n", mahindra[rollnum].name);
                    printf("Age: %d\n", mahindra[rollnum].age);
                    printf("CGPA: %f\n", mahindra[rollnum].cgpa);
                }
            } else if (choice == 2){
                //to display all the students
                
                if (last == -1){
                    //-1 being there is nothing in the list
                    printf("There is no student in the list.\n");
                }else {
                    display(mahindra, last);
                }
            }else if (choice == 1){
                //to add the students

                if (last+1 >= 20){
                    printf("You cant add a new student.\n");
                } else{  
                    last++;
                    printf("Enter the Name: ");
                    getchar();
                    fgets(mahindra[last].name, sizeof(mahindra[last].name), stdin);

                    printf("Enter the Age of the student: ");
                    scanf("%d", &mahindra[last].age);

                    printf("Enter the cgpa of the student: ");
                    scanf("%f", &mahindra[last].cgpa);

                    mahindra[last].rollno = last+1;
                }
            }else if (choice == 4){
                    //to update
                    int updatechoice = 0, rollnum = 0;
                    printf("Enter the roll number of the student you want to update: ");
                    scanf("%d", &rollnum);
                    printf("\n");

                    rollnum = search(mahindra, rollnum, last);
                    printf("1. Update Name\n2. Update Age\n3. Update Cgpa\n4. Update everything\n");

                    printf("What do you want to Update? ");
                    scanf("%d", &updatechoice);

                        if (updatechoice == 1){
                            //to update name
                                printf("Enter the Updated name: ");
                                getchar();
                                    fgets(mahindra[rollnum].name, sizeof(mahindra[rollnum].name), stdin);
                                        printf("\nThe name has been updated.\n");
                        }else if (updatechoice == 2){
                            //to update age
                                printf("Enter the updated age: ");
                                    scanf("%d", &mahindra[rollnum].age);
                                        printf("\nThe age has been updated.\n");
                        }else if (updatechoice == 3){
                            //to update cgpa
                                printf("Enter the updated cgpa: ");
                                    scanf("%f", &mahindra[rollnum].cgpa);
                                        printf("\nThe cgpa has been updated.\n");
                        }else if (updatechoice == 4){
                            //to update everything
                                printf("Enter the Updated name: ");
                                getchar();
                                    fgets(mahindra[rollnum].name, sizeof(mahindra[rollnum].name), stdin);
                                        printf("\nThe name has been updated.\n");

                                        printf("Enter the updated age: ");
                                            scanf("%d", &mahindra[rollnum].age);
                                                printf("\nThe age has been updated.\n");

                                                    printf("Enter the updated cgpa: ");
                                                        scanf("%f", &mahindra[rollnum].cgpa);
                                                            printf("\nThe cgpa has been updated.\n");
                        }
            }else if (choice == 5){
                if (last == -1) printf("You cant delete any students at the moment.\n");
                else {
                    int rollnum = 0;
                    printf("Enter the roll number you want to remove: ");
                    scanf("%d", &rollnum);
                    printf("\n");

                    for (int i = rollnum; i<last; i++){
                        mahindra[i] = mahindra[i + 1];
                    }
                    last -= 1;
                }
            } else if (choice == 6) break;


            printf("You want to continue editing? (y/n)");
            scanf(" %c", &yaorne);
    }

    free(mahindra);
}
