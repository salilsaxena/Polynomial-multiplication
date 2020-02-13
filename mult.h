#include <stdio.h>
#include <stdlib.h>
// #include "mult.h"

typedef struct node
{
  int coeff,exp;
  struct node *next;
}node;
// node * create_list();
// void insert(node**,int,int);
// void insert_beg(node**,int,int);
// void insert_end(node**,int,int);
// void insert_next(node **,int,int);
// void display(node*);
// void del_if_pos(node**);
// void mul(node*,node
node *create_list()
{
  node * head = NULL;
  return head;
}
void insert(node **head,int coef,int expo)
{
	int flag = 0;
	node * tmp = (node*)malloc(sizeof(node));
	tmp->coeff = coef;
  tmp->exp = expo;
	if(*head ==NULL)
	{
		*head = tmp;
		(*head)->next = NULL;
	}
	else if((*head)->exp < expo)
	{
		tmp->next = *head;
		*head = tmp;
	}
	else
	{
		node * crt = *head;
    if(crt->next==NULL)
    {
      if(crt->exp == expo)
      {
        crt->coeff+=coef;
      }
      else if(crt->exp > expo)
      {
        crt->next = tmp;
        tmp->next = NULL;
      }
      else if(crt->exp<expo)
      {
        tmp->next = crt;
      }
    }
    else
    {
    	while(crt->next!=NULL)
  		{
        if(crt->exp == expo)
        {
          crt->coeff += coef;
          break;
        }
  		 if(crt->exp > expo && crt->next->exp < expo)
  			{
          tmp->next = crt->next;
  				crt->next = tmp;
  				break;
  			}

  			crt = crt->next;
  		}
  		if(crt->next==NULL) //none of the while loop conditions fill:
  		{
  			crt->next = tmp;
  			tmp->next = NULL;
  		}
    }
	}
}

void insert_beg(node** head,int c,int e)
{
  node * tmp = (node*)malloc(sizeof(node));
  tmp->coeff =  c;
  tmp->exp = e;
  tmp->next = *head;
  *head = tmp;
}

void insert_next(node** head,int c,int e) // insertion after lasnode is not working
{

  if(*head==NULL)
  {
    insert_beg(head,c,e);
  }
  else if(e>(*head)->exp)
  {
    insert_beg(head,c,e);
  }
  else
  {
    node * tmp = (node*)malloc(sizeof(node));
    tmp->exp = e;
    tmp->coeff = c;
    //to compare e
    node * crt =  *head;
    while(crt != NULL)
    {
      if(crt->exp > e && crt->next->exp < e)
      {
        tmp->next = crt->next;
        crt->next = tmp;
        break;
      }
      if(crt->exp==e)
      {
        crt->coeff +=c;
        free(tmp);
        break;
      }
      crt = crt->next;
    }
  }
}

void insert_end(node **head,int c,int e)
{
  node * tmp = (node*)malloc(sizeof(node));
  tmp->coeff = c;
  tmp->exp = e;
  tmp->next = NULL;
  if(*head == NULL) //empty list
  {
    *head = tmp;
  }
  else
  {
    node * crt = *head;
    while(crt->next !=NULL)
    {
      crt = crt->next;
    }
    crt->next = tmp;
  }
}
void display(node *head)
{
  printf("\n");
  printf("-------------------------------------------\n");
  if(head ==NULL)
  {
    printf("\nEmpty\n");
  }
  else
  {
    node * crt = head;
    while(crt !=NULL)
    {
      if(crt->next!=NULL)
      {
        if(crt->next->coeff < 0)
          printf("%d*x^%d",crt->coeff,crt->exp);
        else
          printf("%d*x^%d+",crt->coeff,crt->exp);
      }
      else
      {
        printf("%d*x^%d",crt->coeff,crt->exp);
      }
      crt = crt->next;
    }
  }
  printf("\n");
  printf("-------------------------------------------\n");
}

void del_if_pos(node **head)
{
  node * crt =*head;
  while(crt->next->next!=NULL)
  {
    crt =crt->next;
  }
  if(crt->next->coeff==0)
  {
    free(crt->next);
    crt->next = NULL;
  }
}
void mul(node* l1_h,node* l2_h)
{
  if(l1_h == NULL || l2_h==NULL)
  {
    printf("\"One of the list is empty\"\n");
  }
  else
  {
    node * temp = create_list();
    node * crt_1 = l1_h;
    node * crt_2 = l2_h;

      while(crt_2!=NULL)
      {
        insert_end(&temp,l1_h->coeff*crt_2->coeff,l1_h->exp+crt_2->exp);
        crt_2 = crt_2->next;
      }
      //uptill this point the first element of list is multiplie with all the other elemets of list2 and creted a new list

      insert_end(&temp,0,0); //just inserting a constant term at the end of newly created list
      crt_1 = l1_h->next;
      crt_2 = l2_h;
      while(crt_1 != NULL)
      {
        crt_2 = l2_h;
        while(crt_2 != NULL)
        {
          insert_next(&temp,crt_2->coeff*crt_1->coeff,crt_2->exp+crt_1->exp);
          crt_2 = crt_2->next;
        }
        crt_1 = crt_1->next;
      }
      if(temp->coeff==0)
      {
        temp = temp->next;
      }
      node* crt =temp;

      del_if_pos(&temp);
      while(crt->next != NULL)
      {
        if(crt->next->coeff == 0)
        {
          crt->next = crt->next->next;
        }
        crt = crt->next;
      }
      display(temp);
    }
}
