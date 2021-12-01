#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void delay(int number_of_seconds) {
	// Converting time into milli_seconds
	int milli_seconds = 1000 * number_of_seconds;

	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + milli_seconds)
		;
}


void setIp(char interface[] ,char ip[],char mask[],char gateway[]){
		char command[128]; // store command in there
	    snprintf(command, sizeof(command),"netsh interface ipv4 set address name=%s static %s mask=%s gateway=%s",interface,ip,mask,gateway);  // convert the commbination of texts and args => to one string
		system(command);	 //execute the command
		
}
void showInterfaceConfig(char interface[]){
		char command[128];
	    snprintf(command, sizeof(command),"netsh interface ipv4 show config %s",interface);
		system(command);
	
}
void setDNS(char interface[],char dns[]){
	char command[128];
	snprintf(command, sizeof(command),"netsh interface ipv4 set dns name=%s static %s",interface,dns);
	system(command);
}

int main() {
	
	system("color 3");
	int arg=0;
	
	char interface[30];
	char mask[17];
	char ip[17];
	char gateway[17];
	char dns[17];
	
	int exit=0;
	system("color 4");
	puts("..................");
	puts("Warning\n");
	delay(1);
	printf("<<this program Developed by Aryana.Bkh >>\n..................\n \n Loading \n  please wait ");
	delay(1);
	printf(" .");
	delay(1);
	printf(" .");
		
	delay(1);
	printf(" \n\n===============");

	delay(1);
	system("color 3");
	printf(" \n enter 1 to show network interfaces\n enter 2 to set ip \n enter 3 to set dns \n enter 4 to see an interface config  /n/n enter 85 to exit");


	
	
	
	while(exit!=1)
	{	
		printf("\n ===============\n enter the arg >>");
		scanf("%d",&arg);
		
		if(arg==1) //show interfaces
			system("Netsh interface ipv4 show interface");
		else if(arg==2)//change ip
		{
			puts("enter interface:");
			scanf("%s",interface);
			puts("\n enter new local Ip:");
			scanf("%s",ip);
			puts("\n enter new mask:");
			scanf("%s",mask);
			puts("\n enter new gateway:");
			scanf("%s",gateway);
			
			setIp(interface,ip,mask,gateway);
		
			
		}	//
		else if(arg==3)
		{
				puts("enter interface:");
			scanf("%s",interface);
			puts("\n enter new DNS:");
			scanf("%s",dns);
			
			setDNS(interface,dns);
		}
		else if(arg==4)
		{
				puts("enter interface:");
			scanf("%s",interface);
		showInterfaceConfig(interface);
			
		}
		else if(arg==85)
			exit=1;
		else
			puts("Wrong arg!");
	}
	return 0;

//	system("ipconfig");
//	printf("\n\n\n\n press any key to exit...\n");
//	getchar();

}
