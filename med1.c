#include<string.h>

void viewMedicines();
void printMenu();
void addToCart();


char name[14][50] = {"First Aid Kit","Ibuprofen","Paracetamol","Dexamethasone","Loratadine","Anthelminthics","Pyrantel","Ampicillin","Linezolid","Dapsone","Amphotericin B","Ribavirin","Quinine","Doxycilin"};
int pri[]={140,588,433,157,153,125,420,154, 147,953,458,125,153,412};



struct node{
	int price;
	int quantity;
	char medname[50];
	struct node *next;
}*top;


void pushMed(struct node *newnode);
void displayBill();

void printMenu(){
   printf("1.View medicines\n");
   printf("2.Add to Cart\n");
   printf("3.View waiting list\n");
   printf("4.Confirm and place order\n");
}


void viewMedicines()
{
	int i;
	for(i=0; i<14; i++)
	{

		printf("%d. %s - %d\n ", i+1 ,name + i , pri[i]);
	}
}


void addToCart()
{
	int medno, quantity ,i;
	struct node *newnode ;
	printf("Enter the medicine number or -1 to exit");
	scanf("%d",&medno);
	i=0;
	while(medno!=-1)
	{	
		
		printf("Enter Quantity");
		scanf("%d", &quantity);

		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->quantity =  quantity;
		newnode->price = pri[medno-1];

		strcpy(newnode->medname ,name + (medno - 1));

		pushMed(newnode);
		
		printf("Enter the medicine number or -1 to exit");
		scanf("%d",&medno);

	}

}


void pushMed(struct node *newnode)
{
	if(top==NULL)
	{
		top = newnode;
		newnode->next= NULL;
	}
	else{
		newnode->next = top;
		top = newnode;
	}
}


int displayCart()
{
	int counter ,sum=0;
	struct node *temp;
	temp = top;
	printf("NO.\tMedicine Name\tQuantity\tPrice\n");
	while(temp!=NULL)
	{
		printf("%d\t%s \t %d \t\t %d \n",++counter , temp->medname , temp->quantity , temp->price );
		sum+= (temp->quantity)* (temp->price);
		temp= temp->next;
	}

	return sum;

}


void displayBill()
{	
	int sum;
	sum=displayCart();
	printf("--------------------------------------------------------------------------------\n");
	printf("Amount-----------------------------%d",sum);
}

void main()
{	
	//viewMedicines();
	addToCart();
	displayCart();
	displayBill();

	getch();
	
}