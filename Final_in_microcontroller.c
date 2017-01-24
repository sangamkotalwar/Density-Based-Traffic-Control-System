#include<16f72.h>
#device adc=10
#include <stdlib.h>
#use delay (clock=20000000)
#fuses HS,NOWDT,NOPROTECT,NOBROWNOUT,NOPUT

int j = 0;
int dt[4]={20,20,20,20};
int vt[4]={0,0,0,0};

int main()
{
   /*output_low(PIN_C0);
   output_high(PIN_C0);//Reset Pin T flip flop*/
   output_low(PIN_B0);
   output_low(PIN_C0);
   output_low(PIN_B1);
   output_low(PIN_C1);
   output_low(PIN_B2);
   output_low(PIN_C2);
   output_low(PIN_B3);
   output_low(PIN_C3);

   while(1)
   {
      //i=0;
      //while(i<4)
      {
          output_high(PIN_B0);
          output_low(PIN_C0);
        //output_low(PIN_B0);
         for(j=0;j<dt[0];j++)               //1
         {
            //if(IR[1] || IR[2] || IR[3])
             if(input(PIN_A1) || input(PIN_A2) || input(PIN_A3))
               output_high(PIN_B4);//Buzzer/Alarm
            //if(IR[0]==0)//motion)
                if(j >= 0.75*dt[0])
                {
                    output_high(PIN_B1);
                    output_high(PIN_C1);
                }
               if(input(PIN_A0) == 0)
               vt[0]++;
            delay_ms(995);
         }
         output_low(PIN_B4); //Buzzer off
         if(vt[0]<(dt[0]/2))
            {
               // if(dt[0]>5)
                //{
                dt[0]+=10;
                if(dt[0] > 40)
                    dt[0] = 40;
                //}
                 //else dt[0] = 5;
            }
         else
            {
                dt[0]-=0.5*vt[0];
                if(dt[0]<5)
                    dt[0]=5;
            }
         //Tu[0];
         //Td[0];
         //output_high(PIN_B0);
         output_low(PIN_B0);
         output_low(PIN_C0);
        // i--;
      }

      {                               //2
         output_high(PIN_B1);
         output_low(PIN_C1);
         //output_low(PIN_B1);
         for(j=0;j<dt[1];j++)               //1
         {

             if(input(PIN_A4) == 1)//ambulance
            {
                //Tu[0];
                //Td[0];
                output_low(PIN_B1);
                output_low(PIN_C1);

                output_high(PIN_B0);
                output_low(PIN_C0);
                while(input(PIN_A4) == 1)
                    delay_ms(10000);
                //Tu[0];
                //Td[0];
                //output_high(PIN_B0);
                output_low(PIN_B0);
                output_low(PIN_C0);

                output_high(PIN_B1);
                output_low(PIN_C1);
            }

                if(j>=0.75*dt[1])
                {
                    output_high(PIN_B2);
                    output_high(PIN_C2);
                }
            //if(IR[1] || IR[2] || IR[3])
             if(input(PIN_A0) || input(PIN_A2) || input(PIN_A3))
               output_high(PIN_B4); //Buzzer/Alarm
            //if(IR[0]==0)//motion)
               if(input(PIN_A1) == 0)
               vt[1]++;
            delay_ms(995);
         }
         output_low(PIN_B4);
         if(vt[1]<(dt[1]/2))
            {
                //if(dt[1]>5)
                //{
                dt[1]+=10;
                if(dt[1] > 40)
                    dt[1] = 40;
                //}
                 //else dt[1] = 5;
            }
         else
            {
                dt[1]-=0.5*vt[1];
                if(dt[1]<5)
                    dt[1] = 5;
            }
         //Tu[0];
         //Td[0];
         //output_high(PIN_B1);
         output_low(PIN_B1);
         output_low(PIN_C1);
         }
         {

         output_high(PIN_B2);
         output_low(PIN_C2);
         //output_low(PIN_B2);
         for(j=0;j<dt[2];j++)               //3
         {
             if(input(PIN_A4) == 1)//ambulance)       //3
            {
                //Tu[0];
                //Td[0];
                output_low(PIN_B2);
                output_low(PIN_C2);

                output_high(PIN_B0);
                output_low(PIN_C0);

                //output_low(PIN_B0);
                while(input(PIN_A4) == 1)
                    delay_ms(30000);
                //Tu[0];
                //Td[0];
                //output_high(PIN_B0);
                output_low(PIN_B0);
                output_low(PIN_C0);

                output_high(PIN_B2);
                output_low(PIN_C2);
            }
            if(j>=0.75*dt[2])
            {
                output_high(PIN_B3);
                output_high(PIN_C3);
            }
            //if(IR[1] || IR[2] || IR[3])
             if(input(PIN_A1) || input(PIN_A0) || input(PIN_A3))
               output_high(PIN_B4); //Buzzer/Alarm
            //if(IR[0]==0)//motion)
               if(input(PIN_A2) == 0)
               vt[2]++;
            delay_ms(995);
         }
         output_low(PIN_B4);
         if(vt[2]<(dt[2]/2))
            {
                //if(dt[2]>5)
                //{
                dt[2]+=10;
                if(dt[2] > 40)              //extreme cases
                    dt[2] = 40;
                //}
                 //else dt[2] = 5;        //if vt <= 5  and/or dt <= 5 then dt = 5
            }
         else
            {
                dt[2]-=0.5*vt[2];
                if(dt[2] < 5)
                    dt[2] = 5;
            }
         //Tu[0];
         //Td[0];
         //output_high(PIN_B2);
         output_low(PIN_B2);
         output_low(PIN_C2);
         }
         {
             output_high(PIN_B3);
             output_low(PIN_C3);
         //output_low(PIN_B3);
         for(j=0;j<dt[3];j++)               //1
         {
             if(input(PIN_A4) == 1)//ambulance)       //4
            {
                //Tu[0];
                //Td[0];
                output_low(PIN_B3);
                output_low(PIN_C3);

                output_high(PIN_B0);
                output_low(PIN_C0);

                //output_low(PIN_B0);
                while(input(PIN_A4) == 1)
                    delay_ms(30000);
                //Tu[0];
                //Td[0];
                //output_high(PIN_B0);
                output_low(PIN_B0);
                output_low(PIN_C0);

                output_high(PIN_B3);
                output_low(PIN_C3);
            }

                if(j>=0.75*dt[3])
                {
                    output_high(PIN_B0);
                    output_high(PIN_C0);
                }
            //if(IR[1] || IR[2] || IR[3])
             if(input(PIN_A1) || input(PIN_A2) || input(PIN_A0))
               output_high(PIN_B4); //Buzzer/Alarm
            //if(IR[0]==0)//motion)
               if(input(PIN_A3) == 0)
               vt[3]++;
            delay_ms(995);
         }
         output_low(PIN_B4);
         if(vt[3]<(dt[3]/2))
            {
                //if(dt[3]>5)
                //{
                dt[3]+=10;
                if(dt[3] > 40)
                    dt[3] = 40;
                //}
                 //else dt[3] = 5;
            }
         else
            {
                dt[3]-=0.5*vt[3];
                if(dt[3] < 5)
                    dt[3] = 5;
            }
         //Tu[0];
         //Td[0];
         output_low(PIN_B3);
         output_low(PIN_C3);
         }
      vt[0]=0;
      vt[1]=0;
      vt[2]=0;
      vt[3]=0;
   }
  return 0;
}
