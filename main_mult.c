/*
  Made by Salil Saxena.
  this is the main fucntion for multiplication of 2 Seprate Polynomial ADT
  Below are defined are two Singly Linked list which accepts sorted elements suc that the elemts of higher power must be inserted first then the others
  Constant term have a power of 0 *as they shiuld have*
*/
#include <stdio.h>
#include<stdlib.h>
#include "mult.h"
void main()
{
  node *l1_h = create_list();
  node *l2_h = create_list();
  node *temp = create_list();;
  int coefficiant,exponent;
  int choice;

  printf("Please insert in order of larger coefficiant first\n");
  while(1)
  {
    printf("Menu:\n1.Insert in list 1\n2.Insert in List 2\n3.Display List 1\n4.Display List 2\n5.Multiply\n6.exit");
    printf("\n:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter the Coeff: ");
        scanf("%d",&coefficiant);
        printf("Enter the Exponent: ");
        scanf("%d",&exponent);
        insert(&l1_h,coefficiant,exponent);
        break;
      case 2:
        printf("Enter the Coeff: ");
        scanf("%d",&coefficiant);
        printf("Enter the Exponent: ");
        scanf("%d",&exponent);
        insert(&l2_h,coefficiant,exponent);
        break;
      case 3:
        display(l1_h);
        break;
      case 4:
        display(l2_h);
        break;
      case 5:
        // printf("bye\n");
        mul(l1_h,l2_h);
        break;
      case 6:
        exit(0);
    }
      // if(choice == 5)
      // {
      //   // printf("EnD\n");
      //   break;
      // }

    }

  // printf("Pls enter the list 1 in oder of highest coefficiant to lowest: \n");
  // char choice  = 'y';
  // do{
  //   printf("\tCoefficiant: ");
  //   scanf("%d",&coefficiant);
  //
  //   printf("\tExponent: ");
  //   scanf("%d",&exponent);
  //   insert_end(&l1_h,coefficiant,exponent);
  //
  //   printf("more?: ");
  //   // getchar(choice);
  //   choice=getchar();
  //   // scanf("%c",&choice);
  // }while(choice == 'y' || choice=='Y');
  //
  // printf("Pls enter the list 2 in oder of highest coefficiant to lowest: \n");
  // choice  = 'n';
  // coefficiant,exponent;
  // do
  // {
  //   printf("\tCoefficiant: ");
  //   scanf("%d",&coefficiant);
  //
  //   printf("\tExponent: ");
  //   scanf("%d",&exponent);
  //   insert_end(&l2_h,coefficiant,exponent);
  //   printf("more?: ");
  //   // scanf("%c\n",&choice);
  //   choice=getchar();
  // }while(choice == 'Y' || choice=='y');

  // insert_end(&l1_h,3,2);
  // insert_end(&l1_h,2,1);
  // insert_end(&l1_h,2,0);
  //
  // insert_end(&l2_h,4,2);
  // insert_end(&l2_h,-7,1);
  // insert_end(&l2_h,5,0);

}
