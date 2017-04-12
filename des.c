#include<stdio.h>
  #include<conio.h>
  #include<string.h>
  #include<malloc.h>
  #include<stdlib.h>
  #include<math.h>
  
  int s1[4][16]={
      14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
      0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
      4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
      15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
      };
  int s2[4][16]={
      15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
      3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
      0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
      13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
      };
  int s3[4][16]={
      10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
      13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
      13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
      1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
      };
  int s4[4][16]={
      7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
      13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
      10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
      3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
      };
  int s5[4][16]={
      2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
      14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
      4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
      11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
      };
  int s6[4][16]={
      12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
      10,15,4,2,7,12,9,5,6,1,12,14,0,11,3,8,
      9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
      4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
      };
  int s7[4][16]={
      4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
      13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
      1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
      6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
      };
  int s8[4][16]={
      13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
      1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
      7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
      2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
      };
  int ip_inverse[8][8]={
      40,8,48,16,56,24,64,32,
      39,7,47,15,55,23,63,31,
      38,6,46,14,54,22,62,30,
      37,5,45,13,53,21,61,29,
      36,4,44,12,52,20,60,28,
      35,3,43,11,51,19,59,27,
      34,2,42,10,50,18,58,26,
      33,1,41,9,49,17,57,25
     };
     int ebin[48],key[64];
     int ch,ch1,temp[32];
     char *entry[500], letter, choice[2],xyz[100];
     int ascii, len, binary[8], t,fbinary[500],ip[64],total[64],final[64];
     int lft_p[32],rit_p[32],lft_k[28],rit_k[28],pc1[57],ck[28],dk[28],keyi[16][48],perm[56];
     int z[48],round_g,xor1[48],sub[32],p[32],xor2[32],ij,km,cypher[64],inv[8][8];
     void string_to_bin();
     void key_gen();
     void intial_perm();
     void expansion();
     void perm_choice1();
     void perm_choice2();
     void xor_one_e(int);
     void substitution();
     void permutation();
     void xor_two();
     void inverse();
     void bin_ascii();
     void xor_twodec();
  int main()
  {
      int i,j,k;
       /******************* Input Plain Text  and Conversion Of Text To Binary*********************/
      string_to_bin();
      /* copying the converted binary to total */   
      printf("\nThe converted binary form of given plane text\n"); 
      for(i=0;i<64;i++)
      {
                        
            printf("%d",fbinary[i]);
            total[i]=fbinary[i];
      }
      /*************************************  input for key ****************************************/
      printf("\n for key -input \n");
      string_to_bin();
      printf("\n the converted key \n");
      for(i=0;i<64;i++)
      {
                        
            printf("%d",fbinary[i]);
            key[i]=fbinary[i];
      }
      printf("\n");
      
      /********************************** intial permutation **************************************/
      intial_perm();
       printf("\n intial permutation of plane  ");
         for(ch1=0;ch1<64;ch1++)
         printf("%d",ip[ch1]);
  
       for(i=0;i<=63;i++)
      {
            final[i]=ip[i];
      }
    
      /********************** deviding into left and right 32 bit data *****************************/
      for(i=0;i<32;i++)
      {
                        lft_p[i]=final[i];

      }
      j=0;
      for(i=32;i<64;i++)
      {
                        rit_p[j]=final[i];
                        j++;

      }
       printf("\nleft part and right part after IP ");
        printf("\n");
         for(ch1=0;ch1<32;ch1++)
         printf("%d",lft_p[ch1]);
      printf("\n");
         for(ch1=0;ch1<32;ch1++)
         printf("%d",rit_p[ch1]);
       
      
      key_gen();

      
      
      /***********************************************  rounds implementation***************************************/
        for(ch=1;ch<=16;ch++)
        {
        
         expansion();
         
         
         
         xor_one_e(ch);
        
         
         substitution();
         
           
         permutation();
      
         
         xor_two();
         
          for(km=0;km<32;km++)
          {
         lft_p[km]=rit_p[km];
         rit_p[km]=xor2[km];
          }

         
         }
      /*****************88 32 bit swap **********************************/
      for(i=0; i<32; i++) cypher[i]=rit_p[i];
      for(; i<64; i++) cypher[i]=lft_p[i-32];
      
      
      /***************** inverse IP ************************/
      inverse();

      printf("\n *****************88 decryption ****************\n");
      for(i=0;i<64;i++)
      total[i]=cypher[i];
      intial_perm();
         
         for(ch1=0;ch1<32;ch1++)
           rit_p[ch1]=ip[ch1];
         for(ch1=32;ch1<64;ch1++)
           lft_p[ch1]=ip[ch1];

             
             
             /************* decryption 16 rounds ************************/
             
             for(ch=16;ch>0;ch--)
             {
                                  
         
         
         
           for(i=0;i<32;i++)
           {
            temp[i]=rit_p[i];
            rit_p[i]=lft_p[i];
            }
          
          

         expansion();
         
        
       
         xor_one_e(ch);
         
        
         substitution();
         
         permutation();
        
         
         xor_twodec();
         
         for(ch1=0;ch1<32;ch1++)
           lft_p[ch1]=xor2[ch1];
         }
         for(ch1=0;ch1<32;ch1++)
           cypher[ch1]=lft_p[ch1];
           ch=0;
           
           for(ch1=32;ch1<64;ch1++)
           {
           cypher[ch1]=rit_p[ch];
           ch++;
           }
           inverse();
           printf("plane in binary after decryption\n");
           for(ch1=0;ch1<64;ch1++)
           printf("%d",cypher[ch1]);
           bin_ascii();           
     
      
      getch();
      return 0;
    } /*end of main()*/
    void string_to_bin()
   {
         
         int i,j=0;
         char entry[501];
        
        printf("Enter string to convert up to 500 chars \n");
        gets(entry);
        len = strlen(entry);  
        
        for(i = 0; i<len; i++)
        {       
                if(t==6)
                             {
                             binary[7] = 0;
                             }
                t= 0;
                letter = entry[i]; 
                ascii = letter;    
                while(ascii>0)    
                {
         
                 if((ascii%2)==0)
                 {
                             binary[t] = 0;
                             ascii = ascii/2;
                             t++;
                             
                 }
                 else
                 {
                  binary[t] = 1;
                  ascii = ascii/2;
                  t++;
                 
                  }
                 }
          /*total--;*/
        while(t>=0)
        {              fbinary[j]=binary[t];
                       j++;
                      /* printf("%d",binary[t]); */
                       t--;
        }
      }
    }
  

    void intial_perm()  /*Initial Permutation */
    {
       int k=58,i;
       for(i=0; i<32; i++)
       {
             ip[i]=total[k-1];
             if(k-8>0) 
               k=k-8;
             else 
               k=k+58;
      }
      k=57;
      
      for( i=32; i<64; i++)
      {
           ip[i]=total[k-1];
           if(k-8>0) k=k-8;
           else k=k+58;
      }
    }
       void expansion()    /*Expansion Function applied on `right' half*/
       {
                        int exp[8][6],i,j,k;
                        for( i=0; i<8; i++)
                        {
                             for( j=0; j<6; j++)
                             {
                                  if((j!=0)||(j!=5))
                                  {
                                     k=4*i+j;
                                     exp[i][j]=rit_p[k-1];
                                  }
                                  if(j==0)
                                   {
                                    k=4*i;
                                    exp[i][j]=rit_p[k-1];
                                   }
                                  if(j==5)
                                   {
                                   k=4*i+j;
                                   exp[i][j]=rit_p[k-1];
                                   }
                             }
                        }
                        exp[0][0]=rit_p[31];
                        exp[7][5]=rit_p[0];
                        k=0;
                        for(i=0; i<8; i++)
                        for(j=0; j<6; j++)
                        ebin[k++]=exp[i][j];
       }
       void perm_choice1() //Permutation Choice-1
       {
           int k=57,i;
           for(i=0; i<28; i++)
           {
                    pc1[i]=key[k-1];
                    if(k-8>0) k=k-8;
                    else k=k+57;
           }
           k=63;
           for( i=28; i<52; i++)
           {
              pc1[i]=key[k-1];
              if(k-8>0) k=k-8;
              else k=k+55;
           }
           k=28;
           for(i=52; i<56; i++)
           {
             pc1[i]=key[k-1];
             k=k-8;
           }
     } 
    void key_gen()
    {

      int i,j,k=0,t;
      int noshift=0,round;
      perm_choice1();
      
      printf("\n");
      for(i=0;i<28;i++)
                        lft_k[i]=pc1[i];
      j=0;
      for(i=28;i<56;i++)
      {
                        rit_k[j]=pc1[i];
                        j++;
      }
      
                   for(i=0; i<28; i++) /* copying the permuted choice 1 result into ck[28] first 28 bit */
                   {
                       ck[i]=pc1[i];
                   }
                   for(i=28; i<56; i++) /* copying the permuted choice 1 result last 28 bit */
                   {
                                   dk[k]=pc1[i];
                                   k++;
                   }
                   
                   for(round=1; round<=16; round++)
                   {
                                if(round==1||round==2||round==9||round==16)
                                    noshift=1;
                                else
                                    noshift=2;
                                while(noshift>0)
                                {
                                      t=ck[0];
                                      for(i=0; i<28; i++)
                                         ck[i]=ck[i+1];
                                      ck[27]=t;
                                      t=dk[0];
                                      for(i=0; i<28; i++)
                                         dk[i]=dk[i+1];
                                      dk[27]=t;
                                      noshift--;
                                }
                                perm_choice2();/* calling permuted choice2 opration */
                                for(i=0; i<48; i++)
                                keyi[round-1][i]=z[i];/* all 16 processed keys store in this keyi[][] */
                   }
                   round_g=round;
                   
                   

        } 
    void perm_choice2()
   { 
     int per[56],i,k; 
     for(i=0; i<28; i++) per[i]=ck[i];
     for(k=0,i=28; i<56; i++) per[i]=dk[k++];
     z[0]=per[13];
     z[1]=per[16];
     z[2]=per[10];
     z[3]=per[23];
     z[4]=per[0];
     z[5]=per[4];
     z[6]=per[2];
     z[7]=per[27];
     z[8]=per[14];
     z[9]=per[5];
     z[10]=per[20];
     z[11]=per[9];
     z[12]=per[22];
     z[13]=per[18];
     z[14]=per[11];
     z[15]=per[3];
     z[16]=per[25];
     z[17]=per[7];
     z[18]=per[15];
     z[19]=per[6];
     z[20]=per[26];
     z[21]=per[19];
     z[22]=per[12];
     z[23]=per[1];
     z[24]=per[40];
     z[25]=per[51];
     z[26]=per[30];
     z[27]=per[36];
     z[28]=per[46];
     z[29]=per[54];
     z[30]=per[29];
     z[31]=per[39];
     z[32]=per[50];
     z[33]=per[46];
     z[34]=per[32];
     z[35]=per[47];
     z[36]=per[43];
     z[37]=per[48];
     z[38]=per[38];
     z[39]=per[55];
     z[40]=per[33];
     z[41]=per[52];
     z[42]=per[45];
     z[43]=per[41];
     z[44]=per[49];
     z[45]=per[35];
     z[46]=per[28];
     z[47]=per[31];
     
     
  }
    void xor_one_e(int round) //for Encrypt
    {
         int i;        
         for(i=0; i<48; i++)
         xor1[i]=ebin[i]^keyi[round-1][i];
     }
   void substitution()
   {
        int a[8][6],k=0,i,j,p,q,count=0,g=0,v,mn,kv;
       int d,b[4];
    
        for(i=0; i<8; i++)
        {
                 for(j=0; j<6; j++)
                 {
                          a[i][j]=xor1[k++];
                 }
        }
        for( i=0; i<8; i++)
        {
             p=1;
             q=0;
             k=(a[i][0]*2)+(a[i][5]*1);
             j=4;
             while(j>0)
             {
             q=q+(a[i][j]*p);
             p=p*2;
             j--;
        }
        count=i+1;
        switch(count)
        {
                     case 1:
                     v=s1[k][q];
                     break;
                     case 2:
                     v=s2[k][q];
                     break;
                     case 3:
                     v=s3[k][q];
                     break;
                     case 4:
                     v=s4[k][q];
                     break;
                     case 5:
                     v=s5[k][q];
                     break;
                     case 6:
                     v=s6[k][q];
                     break;
                     case 7:
                     v=s7[k][q];
                     break;
                     case 8:
                     v=s8[k][q];
                     break;
        }
      
      mn=3;

        while(v>0)
        {

            d=v%2;
            b[mn--]=d;
            v=v/2; 
        }
        while(mn>=0)
        {
            b[mn--]=0;
        }

        for(kv=0; kv<4; kv++)
            sub[g++]=b[kv];
    }
  }
     void permutation()
     {
                            p[0]=sub[15];
                            p[1]=sub[6];
                            p[2]=sub[19];
                            p[3]=sub[20];
                            p[4]=sub[28];
                            p[5]=sub[11];
                            p[6]=sub[27];
                            p[7]=sub[16];
                            p[8]=sub[0];
                            p[9]=sub[14];
                            p[10]=sub[22];
                            p[11]=sub[25];
                            p[12]=sub[4];
                            p[13]=sub[17];
                            p[14]=sub[30];
                            p[15]=sub[9];
                            p[16]=sub[1];
                            p[17]=sub[7];
                            p[18]=sub[23];
                            p[19]=sub[13];
                            p[20]=sub[31];
                            p[21]=sub[26];
                            p[22]=sub[2];
                            p[23]=sub[8];
                            p[24]=sub[18];
                            p[25]=sub[12];
                            p[26]=sub[29];
                            p[27]=sub[5];
                            p[28]=sub[21];
                            p[29]=sub[10];
                            p[30]=sub[3];
                            p[31]=sub[24];
                            
     }
    void xor_two()
    {
         int i;
         for(i=0; i<32; i++)
         {
          xor2[i]=lft_p[i]^p[i];
          }
    }
     void inverse()
     {
         int p=40,q=8,k1,k2,i,j;
         for(i=0; i<8; i++)
         {
            k1=p;
            k2=q;
            for(j=0; j<8; j++)
            {
                     if(j%2==0)
                     {
                               inv[i][j]=cypher[k1-1];
                               k1=k1+8;
                     }
                     else if(j%2!=0)
                     {
                               inv[i][j]=cypher[k2-1];
                               k2=k2+8;
                     }
            }
            p=p-1;
            q=q-1;
         }
         p=0;
         for(i=0; i<8; i++)
         for(j=0; j<8; j++)
         {
            cypher[p]=inv[i][j];
            p++;
         }
     }

 void xor_twodec()
    {
         int i;
         for(i=0; i<32; i++)
         {
          xor2[i]=temp[i]^p[i];
          }
    }
void bin_ascii()
  {
       int i,j,k,l,b1[8],b2[8][8],tot; 
       char s[8];
       i=0;
       for(k=0;k<8;k++) 
        for(l=0;l<8;l++)
        {
          b2[k][l]=cypher[i];
          i++;
        }
         
        for(k=0;k<8;k++)
        {
          b1[k]=0; 
        for(l=0;l<8;l++)
        {
          switch(l)
          {
            case 0:
            b1[k]=b1[k]+b2[k][l]*128;
            break;
            case 1:
            b1[k]=b1[k]+b2[k][l]*64;
            break;
            case 2:
            b1[k]=b1[k]+b2[k][l]*32;
            break;
            case 3:
            b1[k]=b1[k]+b2[k][l]*16;
            break;
            case 4:
            b1[k]=b1[k]+b2[k][l]*8;
            break;
            case 5:
            b1[k]=b1[k]+b2[k][l]*4;
            break;
            case 6:
            b1[k]=b1[k]+b2[k][l]*2;
            break;
            case 7:
            b1[k]=b1[k]+b2[k][l]*1;
            break;
            }
          }
        }
        for(k=0;k<8;k++)
        {
          s[k]=b1[k];
        } 
        printf("\ncypher in ascii\n");
        for(i=0;i<8;i++)
        printf(" %d ",b1[i]);
        printf("\n");
        for(i=0;i<8;i++)
        printf(" %c ",s[i]);
    }