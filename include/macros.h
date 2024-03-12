#ifndef MACROS_H_
#define MACROS_H_

#define HALFOF(num) (num/2)
#define AVG5(num1,num2,num3,num4,num5) ((num1+num2+num3+num4+num5)/5.0)
#define SUM(num1,num2) (num1+num2)
#define MIN(num1,num2) num1<num2?num1:num2
#define MAX(num1,num2) num1>num2?num1:num2
#define SQUARE(num) (num*num)

#define CLOSE_RETURN_NULL(fp) {fclose(fp); return NULL;}
#define CHECK_CLOSE_RETURN_NULL(ptr,fp) {if(!ptr){CLOSE_RETURN_NULL(fp)}}
#define FREE_CLOSE_RETURN_NULL(arr,fp) {free(arr);fclose(fp);return NULL;}




#endif /* MACROS_H_ */
