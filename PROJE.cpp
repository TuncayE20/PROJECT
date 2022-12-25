#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct soru {
	int  soru_ID;
	char soru_metni[1000];
	char sik_A[100];
	char sik_B[100];
	char sik_C[100];
	char sik_D[100];
	char dogru_cevap;
};

struct skorlar {
	 char  kullanici_adi[50];
	 int   skor;
};

void hsec (int diziboyu,int puan) {
	
	int   durum=0,volbaba,volbaba2,kayit,sayac=0;
	int   i,b=1,say;
	char  geciciad[50];
    FILE *vol2;
    FILE  *vol3;
    FILE   *k;
	struct skorlar kullanici[diziboyu+1];
	kayit=diziboyu;
	
	
	         printf("Kullanici adinizi giriniz:");
			 gets(geciciad);
			 gets(geciciad);
			 vol3=fopen("Güncelleme2.txt","w+b");
			 fclose(vol3);
	
	

              vol2=fopen("Skorlar.txt","rb");
              while(!feof(vol2)){
              	 fread(&kullanici[i],sizeof(struct skorlar),1,vol2);
              	 if(strcmp(kullanici[i].kullanici_adi,geciciad)==0){
              	 sayac++;	 
		      }
              }
              fclose(vol2);
              
	
	if(sayac!=0){
	  vol2=fopen("Skorlar.txt","r+b");
	     	for(i=0;i<kayit;i++){
	     		fread(&kullanici[i],sizeof(struct skorlar),1,vol2);
			 }
			 fclose(vol2);
			 
			 
			 for(i=0;i<kayit;i++){
			 	if(strcmp(kullanici[i].kullanici_adi,geciciad)==0){
			 		volbaba2=i;
			 		continue;
				 }
				 else {
				 	vol3=fopen("Güncelleme2.txt","a+b");
				 	fwrite(&kullanici[i],sizeof(struct skorlar),1,vol3);
				 	fclose(vol3);
				 }
			     }
			     
			     
				 kullanici[volbaba2].skor=kullanici[volbaba2].skor+puan;
				 vol2=fopen("Skorlar.txt","w+b");
				 fwrite(&kullanici[volbaba2],sizeof(struct skorlar),1,vol2);
				 fclose(vol2);
				 
				 
				 vol2=fopen("Skorlar.txt","a+b");
				 for(i=0;i<kayit;i++){
				 	if(i!=volbaba2) {
				 		fwrite(&kullanici[i],sizeof(struct skorlar),1,vol2);
					    }
				        }
				         fclose(vol2);
				        printf("Puaniniz basarili bir sekilde kaydedildi.\n");
				         
				         k=fopen("Bilgiler.txt","w+");
		                 fprintf(k,"%d %d",b,kayit);
		                 fclose(k);
		             }
		             else {
		             	printf("Kullanici adi bulunamadi.\n");
					 }
}

void case5 (int kayit) {
	
	int   volbaba3,z,temp,c,girilenler[kayit],kalmadi=0;
	int   b,i,sirala[kayit];
    FILE *vol2;
	FILE *k;
	
	
	kalmadi=0;
	   volbaba3=0;
	struct skorlar kullanici[kayit];
	   vol2=fopen("Skorlar.txt","r+b");
	   for(i=0;i<kayit;i++){
	   fread(&kullanici[i],sizeof(struct skorlar),1,vol2);
	   } 
	   fclose(vol2);
	   
	   for(i=0;i<kayit;i++){
	   	sirala[i]=kullanici[i].skor;
	   }
	   
	   
	   for(i=0;i<kayit;i++){
	   	for(z=0;z<kayit;z++){
	   		if(sirala[i]>sirala[z]){
	   			temp=sirala[i];
	   			sirala[i]=sirala[z];
	   			sirala[z]=temp;
			   }
		       }
		       }
		       
		       
		       for(i=0;i<3;i++){
		       	for(z=0;z<kayit;z++){
		       		if(kullanici[z].skor==sirala[i]){
		       			for(c=0;c<volbaba3;c++){
		       				if(girilenler[c]==z){
		       					kalmadi++;
							   }
						       }
					           }
					   if(kalmadi==0 && kullanici[z].skor==sirala[i]){
	     	           printf("%s %d\n",kullanici[z].kullanici_adi,kullanici[z].skor);
	     	           girilenler[volbaba3]=z;
	     	           volbaba3++;
	     	           break;
		                        }
		               else if(kalmadi!=0){
		               	kalmadi=0;
		               	continue;
					   }         
		            }
			        }
	
}
int main() {
	int   soruID,kayit=0,durum=0,volbaba,volbaba2,volbaba3,z,temp,c,girilenler[kayit],kalmadi;
	int   sayi,i,b=1,ek,sayac=0,abc,soruno,puan,say,gecici,sirala[kayit];
	int   c1=0,c2=0,c3=0,c4=0,c5=0;
	int   soruIDleri[5];
	char  cevaplar[5],girilencevaplar[5],secim,geciciad[1000];
    FILE *a;
    FILE *y;
    FILE *k;
    FILE *x;
    FILE *vol;
    FILE *vol2;
    FILE *vol3;
	srand(time(NULL));
	struct skorlar kullanici[say];
	
	
    k=fopen("Bilgiler.txt","r+");
	fscanf(k,"%d %d",&b,&kayit);
	fclose(k);
	
	printf("                           TEST OYUNU UYGULAMASI\n\n");
    while(1){
	printf("1. Soru ekle\n2. Soru sil\n3. Sorulari goster ve guncelle\n4. Oyun oyna\n5. En yuksek skorlari goster\n6. Cik\n ");
	scanf("%d",&sayi);
	
	struct soru sorular[b];	
	switch(sayi){
		
		case 1:
			
			  b++;	
			  ek=b-2;
			  sorular[ek].soru_ID=b-1;
	          a=fopen("Sorular.txt","ab");
              printf("Soruyu yaziniz:");
              gets(sorular[ek].soru_metni);
              gets(sorular[ek].soru_metni);
              printf("A sikkini yaziniz:");
              gets(sorular[ek].sik_A);
              printf("B sikkini yaziniz:");
              gets(sorular[ek].sik_B);
              printf("C sikkini yaziniz:");
              gets(sorular[ek].sik_C);
              printf("D sikkini yaziniz:");
              gets(sorular[ek].sik_D);
              printf("Cevabi giriniz:");
              scanf("%c",&sorular[ek].dogru_cevap);
	          fwrite(&sorular[ek],sizeof(struct soru),1,a);
              fclose(a);
              printf("Sorunuz basarili bir sekilde kaydedildi.\n");
              break;
              
        case 2:
        	a=fopen("Sorular.txt","rb");	
	          for(i=0;i<b-1;i++) {
	          fread(&sorular[i],sizeof(struct soru),1,a);
	          printf("ID=%d\nSoru: %s\n\n",sorular[i].soru_ID,sorular[i].soru_metni);
              }
              fclose(a);
              
              
              printf("Silmek istediginiz sorunun ID`sini giriniz.\n");
              scanf("%d",&soruID);
              
              
               a=fopen("Sorular.txt","rb");
              for(i=0;i<b-1;i++){
              	 fread(&sorular[i],sizeof(struct soru),1,a);
              	 if(sorular[i].soru_ID!=soruID){
              	 sayac++;	 
		      }
              }
              fclose(a);
              
              
              if(sayac!=b-1){
              vol=fopen("Güncelleme.txt","wb");
              fclose(vol);
              a=fopen("Sorular.txt","rb");
              vol=fopen("Güncelleme.txt","a+b");
              for(i=0;i<b-1;i++){
              	 fread(&sorular[i],sizeof(struct soru),1,a);
              	 if(sorular[i].soru_ID!=soruID){
              	 fwrite(&sorular[i],sizeof(struct soru),1,vol);	 
		      }
	          }
			  fclose(vol);
              fclose(a);
              
              
              a=fopen("Sorular.txt","w+");
              fclose(a);
              a=fopen("Sorular.txt","a+b");
              vol=fopen("Güncelleme.txt","rb");
              for(i=0;i<b-1;i++){
              	 fread(&sorular[i],sizeof(struct soru),1,vol);
              	 sorular[i].soru_ID=i+1;
              	 fwrite(&sorular[i],sizeof(struct soru),1,a);	 
	          }
			  fclose(vol);
              fclose(a);
              b--;
              printf("Silme isleminiz basariyla tamamlandi.\n\n");
              }
              else {
              	printf("Uzgunuz boyle bir ID nolu soru yok.\n");
			  }
			  sayac=0;
              break;
              
        	
         	     
        case 3:
              	
	          a=fopen("Sorular.txt","rb");	
	          for(i=0;i<b-1;i++) {
	          fread(&sorular[i],sizeof(struct soru),1,a);
	          printf("ID=%d\nSoru: %s\n\nA)%s\n\nB)%s\n\nC)%s\n\nD)%s\n\nDogru cevap=%c\n\n\n",sorular[i].soru_ID,sorular[i].soru_metni,sorular[i].sik_A,sorular[i].sik_B,sorular[i].sik_C,sorular[i].sik_D,sorular[i].dogru_cevap);
              }
              fclose(a);
              
              
              printf("Hangi ID nolu soruyu guncellemek istersiniz:");
              scanf("%d",&soruID);
              
              a=fopen("Sorular.txt","rb");
              for(i=0;i<b-1;i++){
              	 fread(&sorular[i],sizeof(struct soru),1,a);
              	 if(sorular[i].soru_ID!=soruID){
              	 sayac++;	 
		      }
              }
              fclose(a);
              
              
              if(sayac!=b-1){
              	
              	
              a=fopen("Sorular.txt","rb");
              for(i=0;i<b-1;i++){
              	 fread(&sorular[i],sizeof(struct soru),1,a);
              	 if(sorular[i].soru_ID==soruID){
              	 printf("ID=%d\nSoru: %s\n\nA)%s\n\nB)%s\n\nC)%s\n\nD)%s\n\nDogru cevap=%c\n\n\n",sorular[i].soru_ID,sorular[i].soru_metni,sorular[i].sik_A,sorular[i].sik_B,sorular[i].sik_C,sorular[i].sik_D,sorular[i].dogru_cevap);	 
		      }
              }
              fclose(a);
              
              
              
             y=fopen("Güncelleme.txt","wb");
              fclose(y);
              a=fopen("Sorular.txt","rb");
              y=fopen("Güncelleme.txt","a+b");
              for(i=0;i<b-1;i++){
              	 fread(&sorular[i],sizeof(struct soru),1,a);
              	 if(sorular[i].soru_ID!=soruID){
              	 fwrite(&sorular[i],sizeof(struct soru),1,y);	 
		      }
	          }
			  fclose(y);
              fclose(a);
              
              
              printf("Sectiginiz sorunun kopyasi yukarida.Sorudaki degisikliklerinizi yapiniz ve lutfen sorunun guncellenmis halini giriniz:\n\n\n");
              a=fopen("Sorular.txt","w+");
              fclose(a);
		      sorular[0].soru_ID=soruID;
	          a=fopen("Sorular.txt","ab");
              printf("Soruyu yaziniz:");
              gets(sorular[0].soru_metni);
              gets(sorular[0].soru_metni);
              printf("A sikkini yaziniz:");
              gets(sorular[0].sik_A);
              printf("B sikkini yaziniz:");
              gets(sorular[0].sik_B);
              printf("C sikkini yaziniz:");
              gets(sorular[0].sik_C);
              printf("D sikkini yaziniz:");
              gets(sorular[0].sik_D);
              printf("Cevabi giriniz:");
              scanf("%c",&sorular[0].dogru_cevap);
	          fwrite(&sorular[0],sizeof(struct soru),1,a);
              fclose(a);
              
              
              
              a=fopen("Sorular.txt","ab");
              y=fopen("Güncelleme.txt","rb");
              for(i=1;i<b-1;i++){
              	 fread(&sorular[i],sizeof(struct soru),1,y);
              	  if(sorular[i].soru_ID!=soruID){
              	 fwrite(&sorular[i],sizeof(struct soru),1,a);	 
		  }	
	          }
			  fclose(y);
              fclose(a);
		      printf("Guncelleme isleminiz basariyla tamamlandi.\n\n");
		      }
		      
		      
		      else {
		      	printf("Uzgunuz boyle bir ID nolu soru yok.\n");
			  }
		      sayac=0;
              break; 
		
		case 4:
			
		  puan=0;	
		  x=fopen("Rand.txt","w+");
          fclose(x);
          
		  
		for(i=0;i<5;i++){
    	   while(1){
    		   abc=rand()%(b-1)+1;
    		   x=fopen("Rand.txt","a+");
    		   fscanf(x,"%d %d %d %d %d",&c1,&c2,&c3,&c4,&c5);
    		   if(abc!=c1 && abc!=c2 && abc!=c3 && abc!=c4 && abc!=c5){
    				fprintf(x,"%d ",abc);	
    				fclose(x);
    				break;
				}	
		        }	
	            }	
	            
	            
	    x=fopen("Rand.txt","r+");
        fscanf(x,"%d %d %d %d %d",&soruIDleri[0],&soruIDleri[1],&soruIDleri[2],&soruIDleri[3],&soruIDleri[4]);
        fclose(x);   
		
		
		for(i=0;i<5;i++){
		soruno=i+1;
		a=fopen("Sorular.txt","rb");
		while(!feof(a)){
		fread(&sorular[i],sizeof(struct soru),1,a);
		cevaplar[i]=sorular[i].dogru_cevap;
		if(sorular[i].soru_ID==soruIDleri[i]){
			printf("Soru:%d\n%s\n\nA)%s\n\nB)%s\n\nC)%s\n\nD)%s\n\n",soruno,sorular[i].soru_metni,sorular[i].sik_A,sorular[i].sik_B,sorular[i].sik_C,sorular[i].sik_D);
			printf("Cevabi giriniz:");
			scanf(" %c",&girilencevaplar[i]);
			if(girilencevaplar[i]==cevaplar[i]){
				puan++;
				break;
			}
			else{
				break;
			}
		}
	    }
	    fclose(a);
	    } 
	    
		
		printf("Skor:%d\n\n",puan);    
		printf("Yeni bir kullanicimisiniz?\n");
	    printf("1.Yeni iseniz E`ye basiniz.\n2.Daha onceden kayitli iseniz H`ye basiniz.\n");
	    scanf(" %c",&secim);
	    if(secim=='E'){
	    		struct skorlar kullanici[say];
	             kayit++;
	        if(kayit==1){
	        	printf("Yeni bir kullanici adi olusturunuz:");
	        	gets(kullanici[kayit-1].kullanici_adi);
	        	gets(kullanici[kayit-1].kullanici_adi);
	        	kullanici[kayit-1].skor=puan;
	        	vol2=fopen("Skorlar.txt","a+b");
	        	fwrite(&kullanici[kayit-1],sizeof(struct skorlar),1,vol2);
	        	fclose(vol2);
	        	printf("Kaydiniz basarili bir sekilde olusturuldu.\n");
			}
			else {
				durum=0;
				vol2=fopen("Skorlar.txt","r+b");
				for(i=0;i<kayit-1;i++){
					fread(&kullanici[i],sizeof(struct skorlar),1,vol2);
				}
				fclose(vol2);
					printf("Yeni bir kullanici adi giriniz:");
					gets(kullanici[kayit-1].kullanici_adi);
					gets(kullanici[kayit-1].kullanici_adi);
					kullanici[kayit-1].skor=puan;
					while (1){	
					vol2=fopen("Skorlar.txt","rb");
					i=0;
					volbaba=0;
					while(i<kayit-1 && volbaba==0){
					while(!feof(vol2)){
						fread(&kullanici[i],sizeof(struct skorlar),1,vol2);
						if(strcmp(kullanici[i].kullanici_adi,kullanici[kayit-1].kullanici_adi)==0){
							printf("Girdiginiz kullanici adi kullaniliyor.\n");
							printf("Yeni bir kullanici adi giriniz:");
					        gets(kullanici[kayit-1].kullanici_adi);	
							volbaba++;
							break;
						}
						i++;
						break;
					}
				    }
					fclose(vol2);
					
					
					if (volbaba!=0){
						
						continue;
					}
				    if(volbaba==0) {
						printf("Kaydiniz basarili bir sekilde olusturuldu.\n");
						vol2=fopen("Skorlar.txt","a+b");
						fwrite(&kullanici[kayit-1],sizeof(struct skorlar),1,vol2);
						fclose(vol2);
						break;
				      }
				}
			}
			
            }
	           
	     
	       else if(secim=='H'){
	              hsec(kayit,puan);	 
		 } 
	   break;  
	   
	   case 5:
	       case5(kayit);		        
    break;
	     }
if(sayi==6){
		k=fopen("Bilgiler.txt","w+");
		fprintf(k,"%d %d",b,kayit);
		fclose(k);
		break;
	}
}
	return 0;
}
