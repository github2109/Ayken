#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define N 100
void TiepTuc() {
	printf("\n\nBam phim bat ky de tiep tuc...");
	getch();
	system("cls");
}
void saveFile(int index){
	printf("Ban co muon luu lai file data nay khong (c,k) ?\n");
		getchar();
		char suggest;
		scanf("%c", &suggest);
		if(suggest=='c'){
				char a,name[10],temp[10];
				FILE *fp1,*fp2;
				fflush(stdin);
				printf("Hay dat ten cho file nay :");
				gets(name);
				if(index==1){
					strcpy(temp, name);
					strcpy(name, "Result/");
					strcat(name, temp);
					strcpy(temp, "Result");
					fp1 = fopen("Temp/temp.txt","r");
					fp2 = fopen(name,"w");
				}else{
					FILE *f=fopen("infoData.txt","a");
					fprintf(f,"\n%s",name);
					fclose(f);
					strcpy(temp, name);
					strcpy(name, "Data/");
					strcat(name, temp);
					strcpy(temp, "Data");
					fp1 = fopen("Temp/temp2.txt","r");
					fp2 = fopen(name,"w");
				}
				a = fgetc(fp1);
				while(a!=EOF){
					fputc(a,fp2);
				 	a = fgetc(fp1);
				};
				printf("File da duoc luu thanh cong, hay kiem tra trong thu muc %s",temp);
				fclose(fp1);
				fclose(fp2);
			}
		else{
				printf("File chua duoc luu !");
				TiepTuc();
			}
}
void typeData(float x[], float y[],int &n){
		FILE *fTemp=fopen("Temp/temp2.txt","w");
		printf("Nhap so phan tu : ");
	    scanf("%d",&n);
	    fprintf(fTemp,"%d\n",n);
		for(int i=0;i<n;i++)
		{
			printf("x[%d]=",i);
			scanf("%f",&x[i]);
			fprintf(fTemp,"%.2f ",x[i]);
		}
		fprintf(fTemp,"\n");
		for(int i=0;i<n;i++)
		{
			printf("y[%d]=",i);
			scanf("%f",&y[i]);
			fprintf(fTemp,"%.2f ",y[i]);
		}
		fclose(fTemp);
}
void getData(float x[], float y[],int &n) { 
	int a;
	char temp;
	printf("\n\n1 : Nhap truc tiep tu ban phim ");
	printf("\n2 : Nhap tu File ");
	printf("\nMoi ban nhap lua chon : ");
	scanf("%d",&a);
	if(a==1)
	{   
		typeData(x,y,n);
		saveFile(2);
	}
	else if(a==2){
	printf("Cac file data hien co :\n");
	FILE *f = fopen("infoData.txt","r");
				temp = fgetc(f);
				while(temp!=EOF){
					printf("%c",temp);
					temp = fgetc(f);
				};
	fclose(f);
	printf("\nMoi ban nhap ten File : ");
	char fnamer[10],ftemp[10];	
	FILE *fp;
	scanf("%s",&fnamer);
	strcpy(ftemp, fnamer);
	strcpy(fnamer, "Data/");
	strcat(fnamer, ftemp);
	fp=fopen(fnamer,"rt");
	if(fp==NULL) {
		printf("\n%s Khong Tim thay File!",fnamer);
		getData(x,y,n);
	}else{
		fscanf(fp,"%d",&n);
		for(int i=0;i<n;i++){
			fscanf(fp,"%f",&x[i]);
	    }
		for(int i=0;i<n;i++){
			fscanf(fp,"%f",&y[i]);
	    }
	fclose(fp);
	}}
	else 
	{   
        printf("\nKiem tra lai lua chon!");
		getData(x,y,n);
	}
}
void getc(int &check, float x[],float y[], int &n, float &c){
	int import = true; 
	int i;
	float max=x[0], min=x[0];	
	for(int i=0;i<n;i++){
		if(max < x[i]) max = x[i];
		if(min > x[i]) min = x[i];
	}
    printf("\nMoi ban nhap gia tri can tinh : c = ");
	scanf("%f",&c);
	if(c > max || c < min) import = false;
	while(!import){
		printf("Gia tri c ban nhap khong thoa man dieu kien , xin moi nhap lai:\nc = ");
		scanf("%f",&c);
		if(c > max || c < min) import = false;
		else import = true;
	}
	for( i=0;i<n;i++){
		if(c == x[i]) {
			printf("f(%.2f) ~~ %.3f\n",c,y[i]);
			check = false;
		}
	}
}

void xuatxy(float x[], float y[],int n){
	printf("\n+---------+---------+");
	printf("\n|    x    |    y    |");
	printf("\n+---------+---------+");
	for(int i=0;i<n;i++){
	printf("\n| %6.2f  | %6.2f  |",x[i],y[i]);
	}
	printf("\n+---------+---------+\n");
}
void Ayken1(float x[], float y[],float c,int n){
	float w=1,s=0,d;
	FILE *FileTemp=fopen("Temp/temp.txt","w");
	printf("\n\tBANG NOI SUY AYKEN 1:\n");
	fprintf(FileTemp,"\tBANG NOI SUY AYKEN 1:\n");
	for(int i=0;i<n;i++){
		w=w*(c-x[i]);
		d=c-x[i];
		for(int j=0;j<n;j++){
			if(i==j) {
			printf("|%6.2f|",c-x[i]);
			fprintf(FileTemp,"|%6.2f|",c-x[i]);
			}
			else{
				printf("|%6.2f|",x[i]-x[j]);
				fprintf(FileTemp,"|%6.2f|",x[i]-x[j]);
				d=d*(x[i]-x[j]);
			}
		}
		printf(" | %6.2f |",d);
		fprintf(FileTemp," | %6.2f |",d);
		s=s+y[i]/d;
		printf("\n");
		fprintf(FileTemp,"\n");
	}
	printf("==> f(%.2f) ~~ %.3f\n",c,w*s);
	fprintf(FileTemp,"==> f(%.2f) ~~ %.3f\n",c,w*s);
	fclose(FileTemp);
}
void Ayken2(float x[], float y[],float c,int n){
	float k[n],d;
	k[0]=y[0];
	FILE *FileTemp=fopen("Temp/temp.txt","w");
	printf("\n\t\tBANG NOI SUY AYKEN 2:\n");
	fprintf(FileTemp,"t\t\tBANG NOI SUY AYKEN 2:\n");
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(i>=j){
				if(j==1) d=y[i];
				d=(k[j-1]*(x[i]-c)-d*(x[j-1]-c))/(x[i]-x[j-1]);
				printf("|%6.3f|",d);
				fprintf(FileTemp,"|%6.3f|",d);
			}else{
			printf("\t");
			fprintf(FileTemp,"\t");
			}
		}
		k[i]=d;
		printf("|%6.3f|\n",x[i]-c);
		fprintf(FileTemp,"|%6.3f|\n",x[i]-c);
	}
	printf("==> f(%.3f) ~~ %.3f\n",c,k[n-1]);
	fprintf(FileTemp,"==> f(%.3f) ~~ %.3f\n",c,k[n-1]);
	fclose(FileTemp);
	
}
void start(){
	printf("\t\t\t\t==========================================================\n\n");
	printf("\t\t\t\t              CHAO MUNG BAN DEN VOI DO AN                 \n\n");
	printf("\t\t\t\t         TINH GIA TRI DUA TREN BAN NOI SUY AYKEN          \n\n");
	printf("\t\t\t\t                 SINH VIEN THUC HIEN                      \n\n");
	printf("\t\t\t\t                  DINH QUANG HIEP                         \n\n");
	printf("\t\t\t\t                  NGUYEN KHAC DAT                         \n\n");
	printf("\t\t\t\t==========================================================");}

void menu1(){
	printf("\n\n"                                                           );
	printf("\t\t\t\t========================================================= \n\n"); 
	printf("\t\t\t\t                        MENU                              \n\n");
	printf("\t\t\t\t                   1.BANG NOI SUY AYKEN 1                 \n\n");
	printf("\t\t\t\t                   2.BANG NOI SUY AYKEN 2                 \n\n");
	printf("\t\t\t\t                   3.NHAP DU LIEU KHAC                    \n\n");
	printf("\t\t\t\t                   4.EXIT                                 \n\n");
	printf("\t\t\t\t========================================================="); 
	printf("\t\t\t\t\n              	LUA CHON CUA BAN (1->4):"); 
}
int main(){
	int n,w,check = true;
	system("color 0E");
    start();
	float x[100],y[100],c;
	for(int i=0;i<100;i++){
		x[i]=NULL;
		y[i]=NULL;
	}
	getData(x,y,n);
	xuatxy(x,y,n);
	TiepTuc();

	while(1){
	    xuatxy(x,y,n);
		menu1();
		scanf("%d",&w);
		switch(w){
			case 1:	
				getc(check,x,y,n,c);
				if (check){
					Ayken1(x,y,c,n);
					saveFile(1);
					TiepTuc(); 
					
				}
				else {
					TiepTuc();
					break;
				}
				break;
			case 2:
				getc(check,x,y,n,c);
				if (check){
					Ayken2(x,y,c,n); 
					saveFile(1);
					TiepTuc();
				}
				else {
					TiepTuc();
					break;
				}
				break;
			case 3:
				for(int i=0;i<n;i++)
				{
					x[i]=NULL;
					y[i]=NULL;
				}
				getData(x,y,n);
				xuatxy(x,y,n);
				TiepTuc();
				break;
			case 4:
				printf("KET THUC CHUONG TRINH!");
				return 0;
			default :
				{   system("cls");
					printf("Ban vui long kiem tra lai! \n");
				}
		}
	}	
}

