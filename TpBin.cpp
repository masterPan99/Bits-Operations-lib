#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>

void ShowBin(uint8_t n);
void Show_bin32(uint32_t n);
int Set_Bit32(uint32_t data,int bit_pos,bool bit_value);//numero a modificar,posicion,booleno si va negativo o positivo 
int Bit_Knoler(uint32_t N,int bit_pos);

struct byte32//mapa de bits
{
    uint32_t Dia : 5;//lsb
    uint32_t Mes : 4;
    uint32_t Año :7;
    uint32_t Inpagos :5;
    uint32_t Decimal :5;
    uint32_t Entero : 6;//Msb

    
};

int main()
{
    byte32 A;
    A.Año;
    uint32_t n= 8;
   // ShowBin(n);
    //printf("\n");
    uint32_t AUX;
    AUX=Set_Bit32(n,4,false);
    //uint32_t n= 127;
    printf("%u",AUX);
    
   // Set_Bit32(n,8,true);
   
   /*for(int i=0;i<8;i++)//este for demuestra como se deplazan los numeron binarios
   {
      printf("%d\n",1<<i);
   }*/
  //  Desliz(n);
 // Set_Bit32(n,8,true);
   //printf("%d",4&8);
    return 0;
}

void ShowBin(uint8_t n)
{
    int CantBit = sizeof(n)*8;
    int j=0;
    for(int i=0;i<CantBit;i++)
    {
       printf("%d",(n>>CantBit-1-i)&1);
       j++;
       //printf("\n");
       if(j==4)
       {
          printf(" ");
          j=0;
       }
    }
}

void Show_bin32(uint32_t n)
{
    int CantBit = sizeof(n)*8;
    int j=0,s=0,r=0;
    for(int i=0;i<CantBit;i++)
    {
       printf("%d",(n>>CantBit-1-i)&1);//esta linea funciona
       //printf("%d",n&(1<<i));
       j++,s++;
       //printf("\n");
       if(j==4)
       {
          printf(" ");
          j=0;
       }
       //if (s==8)
       {
        if(r<3)
        {
            printf(" - ");
            s=0;
            r++;
        }
       }
    }
}

int Set_Bit32(uint32_t data,int bit_pos,bool bit_value)
{
    Show_bin32(data);
    printf("\n");
    //printf("%d",bit_pos);
    uint32_t Pos,dataux;
    for (int i=0;i<=bit_pos;i++)
    {
        if(i==bit_pos-1)
        {
            Pos=(1<<i);
            Show_bin32(Pos);
            printf("\n");
            printf("%d\n",Pos);
        }
    }
    if(bit_value==true)
    {
       if(Bit_Knoler(data,bit_pos)==1)
       {
           //No hacemos nada ya hay un 1 
       }
       if(Bit_Knoler(data,bit_pos)==0)
       {
         // hacemos un or
         dataux=(data<<bit_pos)|1;
       }
    }
    if(bit_value==false)
    {
       if(Bit_Knoler(data,bit_pos)==1)
       {
           //^ alt94
           dataux=((data<<bit_pos)^1);
       }
       if(Bit_Knoler(data,bit_pos)==0)
       {
         // hacemos un or
         dataux=(data<<bit_pos)|1;
       }
    }
    //vemos que tenemos:

    
   
    Show_bin32(dataux);

     
}
int Bit_Knoler(uint32_t N,int bit_pos)//nos indica el valor del bit en dicha posicion.
{
    uint8_t n=1,K;
    N<<bit_pos;//N modificado para bit_pos.
    K=(n&N);//K es el resultado de la operacion and// si hay un uno K=1, sino K=0.
    return K;
}