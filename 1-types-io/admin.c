//
// Created by gaosiqi on 2025/2/6.
//
#include <stdio.h>
#include <math.h>
#include <ctype.h>
int main(){
  char first_name[] = "Dayou";
  char last_name[] = "Luo";
  char gender = 'm';//一个字符用单引号
  int birth_year = 1954;
  int birth_month = 7;
  int birth_day = 20;
  char weekday[] = "Tuesday";
  int c_score = 30;
  int music_score = 100;
  int medicine_score = 85;

  double mean = (c_score + music_score + medicine_score) / 3.0;
  double sd = sqrt((pow(c_score - mean,2) + pow(music_score - mean,2) + pow(medicine_score - mean,2)) / 3.0);
  int rank = 5;
  //%.2d:最少输出的位数，不够补0
  printf("%s \t %s \t %c\n"
         "%.2d-%d-%d %.3s.\n"//控制输出星期的缩写
         "%d \t %d \t %d\n"
         "%.1f \t %.2f %d%%\n", first_name, last_name, toupper(gender),
         birth_month, birth_day, birth_year,weekday,
         c_score, music_score, medicine_score,
         mean,sd,rank);
  return 0;
}