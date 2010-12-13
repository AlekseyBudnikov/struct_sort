#include <stdio.h>
#include <stdlib.h>

struct EVENT
{
    int day;
    int mon;
    int year;
    EVENT *next;
};

EVENT *head;

EVENT* add(EVENT *head)
{
	EVENT *event=new EVENT;
    printf("Enter date: ");
    scanf("%d.%d.%d",&(event->day),&(event->mon),&(event->year));
    printf("\n");
	event->next=head;
	head=event;
}

EVENT* list(EVENT *head)
{
	EVENT *event=head;
	while(event)
	{
		printf("Date: %d.%d.%d\n",event->day,event->mon,event->year);
		event=event->next;
	}
	printf("\n");
}

EVENT* find(EVENT *head,int num)
{
    EVENT *event=head;

	while(event)
	{
		if((event->day==num) || (event->mon==num) || (event->year==num))
		{
            printf("Date: %d.%d.%d\n",event->day,event->mon,event->year);
            event=event->next;
		}
		event=event->next;
	}
}

EVENT* swap(EVENT *event,EVENT *event2)
{
    int tmp_day,tmp_mon,tmp_year;

    tmp_day=event->day;
    tmp_mon=event->mon;
    tmp_year=event->year;

    event->day=event2->day;
    event->mon=event2->mon;
    event->year=event2->year;

    event2->day=tmp_day;
    event2->mon=tmp_mon;
    event2->year=tmp_year;
}

EVENT* swap_hand(EVENT *head)
{
    EVENT *event;
    EVENT *event2;

    int day_1,day_2,mon_1,mon_2,year_1,year_2;

    printf("Enter first date: ");
    scanf("%d.%d.%d",&day_1,&mon_1,&year_1);
    printf("\nEnter first date: ");
    scanf("%d.%d.%d",&day_2,&mon_2,&year_2);
    printf("\n");

    for(event=head;event;event=event->next)
        for(event2=head;event2;event2=event2->next)
            if(event->day==day_1 && event->mon==mon_1 && event->year==year_1 && event2->day==day_2 && event2->mon==mon_2 && event2->year==year_2)
                swap(event,event2);

}

EVENT* impractical_sort(EVENT *head)
{
    EVENT *event;
    EVENT *event2;

    for(event=head;event;event=event->next)
        for(event2=head;event2;event2=event2->next)
            if((event->day)+((event->mon)-1)*30+(event->year)*12*30 > (event2->day)+((event2->mon)-1)*30+(event2->year)*12*30 )
                swap(event,event2);
}

EVENT* minmax(EVENT *head)
{
    int min,max;
    int a_min,b_min,c_min,a_max,b_max,c_max;

    EVENT *event;

    min=max=(head->day)+((head->mon)-1)*30+(head->year)*12*30;
    a_min=a_max=head->day;
    b_min=b_max=head->mon;
    c_min=c_max=head->year;

    for(event=head;event;event=event->next)
    {
        if((event->day)+((event->mon)-1)*30+(event->year)*12*30 < min)
        {
            min=(event->day)+((event->mon)-1)*30+(event->year)*12*30;
            a_min=event->day;
            b_min=event->mon;
            c_min=event->year;
        }
        if((event->day)+((event->mon)-1)*30+(event->year)*12*30 > max)
        {
            max=(event->day)+((event->mon)-1)*30+(event->year)*12*30;
            a_max=event->day;
            b_max=event->mon;
            c_max=event->year;
        }
    }

    printf("Min date: %d.%d.%d\n",a_min,b_min,c_min);
    printf("Max date: %d.%d.%d\n\n",a_max,b_max,c_max);
}

EVENT* grouping(EVENT *head)
{
    EVENT *event;
    EVENT *event2;

    int day_all,day_1,mon_1,year_1;

    printf("Enter date: ");
    scanf("%d.%d.%d",&day_1,&mon_1,&year_1);
    printf("\n");
    day_all=day_1+(mon_1-1)*30+year_1*12*30;

    for(event=head;event;event=event->next)
    {
        for(event2=head;event2;event2=event2->next)
        {
            if((event->day)+((event->mon)-1)*30+(event->year)*12*30 <= day_all);
            else if((event2->day)+((event2->mon)-1)*30+(event2->year)*12*30 > day_all);
                else
                    swap(event,event2);
        }
    }


}

EVENT* quick_sort(EVENT *head)
{

}

int menu(void);

int main()
{
    EVENT *head=NULL;

    int n;

    for(;;)
    {
        switch(menu())
        {
            case 1:
                head=add(head);
                break;
            case 2:
                printf("Enter day or month or year: ");
                scanf("%d",&n);
                printf("\n");
                find(head,n);
                break;
            case 3:
                swap_hand(head);
                break;
            case 4:
                minmax(head);
                break;
            case 5:
                grouping(head);
                break;
            case 6:
                impractical_sort(head);
                break;
            case 7:
                quick_sort(head);
                break;
            case 8:
                list(head);
                break;
            case 9:
                exit(0);
                break;
        }
    }

	return 0;
}

int menu()
{
    int c;

    printf("1. Add\n");
    printf("2. Find\n");
    printf("3. Swap\n");
    printf("4. Min,Max\n");
    printf("5. Grouping\n");
    printf("6. Impractical sort\n");
    printf("7. Quick sort\n");
    printf("8. List\n");
    printf("9. Exit\n");

    do
    {
        printf("\nEnter number: ");
        scanf("%d",&c);
        printf("\n");
    }
    while(c<0 || c>9);

    return c;
}
