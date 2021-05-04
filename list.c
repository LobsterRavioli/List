#include<stdio.h>
#include<stdlib.h>
#include"item.h"
#include"list.h"

struct node
{
	item value;
	struct node *next;
};

list newList(void)
{
	return NULL;

}

int emptyList(list l)
{
	return l==NULL;

}

list consList(item val,list l)
{
	struct node *nuovo;
	nuovo=malloc(sizeof(struct node));
	if(nuovo!= NULL)
	{
		nuovo->value=val;
		nuovo->next=l;
		l=nuovo;

	}
	return l;

}

list tailList(list l)
{
	list temp;
	if(l!=NULL)
		temp=l->next;
	else
		temp=NULL;
	return temp;
}

item getFirst(list l)
{
	item e;
	if(l!=NULL)
		e=l->value;
	else 
		e=NULLITEM;
	return e;

}

int sizeList(list l)
{
	int n=0;
	while(!emptyList(l))
	{
		n++;
		l=tailList(l);

	}
	return n;

}

int posItem(list l,item val)
{
	int pos=0;
	int found=0;
	while(!emptyList(l) && !found)
	{
		if(eq(getFirst(l),val))
			found=1;
		else
		{
			pos++;
			l=tailList(l);
		
		} 
	}
	if(!found)
		pos=-1;
	return pos;
}

list reverseList(list l)
{
	list l1;
	item val;
	l1=newList();
	while(!emptyList(l))
	{
		val=getFirst(l);
		l1=consList(val,l1);
		l=tailList(l);

	}
	return l1;
}

void outputList(list l)
{
	int i=0;
	item val;
	while(!emptyList(l))
	{
		val=getFirst(l);
		printf("Elemento di posizione %d:",i);
		output_item(val);
		printf("\n");
		l=tailList(l);
		i++;

	}

}

list inputList(int n)
{
	item val;
	list l=newList();
	for(int i=0;i<n;i++)
	{
		printf("Elemento di posizione %d:",i);
		input_item(&val);
		l=consList(val,l);
		
	}
	return reverseList(l);

}

list garbage_insertList(list l,int pos,item val)//senza interferenze ma rimane elementi non accessibili
{
	item x;
	int i=0;
	list ltmp=newList();
	list lo=newList();
	while(i<pos && !emptyList(l))
	{
		x=getFirst(l);
		ltmp=consList(x,ltmp);
		l=tailList(l);
		i++;

	}
	if(i==pos)
	{
		lo=consList(val,l);
		while(!emptyList(ltmp))
		{
			x=getFirst(ltmp);
			lo=consList(x,lo);
			ltmp=tailList(ltmp);
		}
	}
	return(lo);
}

list insertList(list l,int pos,item val)
{
	if(pos==0)
		return consList(val,l);
	int i=0;
	list prec=l;
	while(i<pos-1 && prec != NULL)
	{
		prec=prec->next;
		i++;		
	}
	if(prec==NULL)
		return l;

}

list removeList(list l,int pos)
{
	list l1;
	if(pos==0 && l!=NULL)
	{
		l1=l;
		l=tailList(l);
		free(l1);
	}
	else
	{
		int i=0;
		list prec=l;
		while(i<pos-1 && prec!=NULL)
		{
			prec=prec->next;
			i++;

		}
	}

	if(prec!=NULL && prec->next != NULL)
		l1=prec->next;
	prec->next=l1->next;
	free(l1);

	}

}
