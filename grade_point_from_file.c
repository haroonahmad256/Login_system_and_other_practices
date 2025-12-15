#include <stdio.h>

float gradepoint(int total_marks){
    float gpa;
    if (total_marks>85)
    {
        gpa= 4.0;
        return gpa;
    }
    if (total_marks>=80)
    {
        gpa= 3.8;
        return gpa;
    }
    if (total_marks>=75)
    {
        gpa= 3.4;
        return gpa;
    }
    if (total_marks>=70)
    {
        gpa= 3.0;
        return gpa;
    }
    if (total_marks>60)
    {
        gpa= 2.0;
        return gpa;
    }
    if (total_marks>=50)
    {
        gpa=  1.0;
        return gpa;
    }
    if (total_marks<50)
    {
        gpa= 0.0;
        return gpa;
    }
    
}

int main(){
    FILE* fptr;
    FILE* fptr2;
    fptr= fopen("Book1.csv", "r");
    fptr2= fopen("Book1_sub.csv", "w");
    int m1, m2, m3, m4, m5;
    int numbers_total;
    int average;
    fprintf(fptr2, "Subjects: s1 s2 s3 s4 s5 Gradepoint\n");
    int i=1;
    while (fscanf(fptr, "%d %d %d %d %d", &m1, &m2, &m3, &m4, &m5)==5)
    {
        numbers_total= m1+m2+m3+m4+m5;
        average= numbers_total/5;
        fprintf(fptr2, "student%d: %d %d %d %d %d %.2f\n",i, m1, m2, m3, m4, m5, gradepoint(average));
        i++;
    }

    fclose(fptr);
}