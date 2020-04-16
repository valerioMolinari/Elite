/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package time;

/**
 *
 * @author Cristian
 */
public class Time 
{
        private int hour;	// Variabili di istanza //Essendo private non possono essere richiamate da altre classi
        private int minute;	// Variabili di istanza
        private double second;	// Variabili di istanza

        public Time()	
        {
          this.hour = 0;	// Costruttore di oggetti per variabili di istanza
          this.minute = 0;	// Costruttore di oggetti per variabili di istanza
          this.second = 0.0;	// Costruttore di oggetti per variabili di istanza
        }

        public Time(int hour, int minute, double second) 
        {
          this.hour = hour;		// Costruttore di oggetti per variabili di istanza
          this.minute = minute;		// Costruttore di oggetti per variabili di istanza
          this.second = second;		// Costruttore di oggetti per variabili di istanza
        }

        public void printTime() 	//Serve per poter richiamare la stampa dell'orario
        {
            while (this.second >= 60.0) 
                this.second -= 60.0;
            while (this.minute >= 60) 
                this.minute -= 60;
            while (this.hour >= 24) 
                this.hour -= 24;
            System.out.printf("%02d:%02d:%04.1f\n",this.hour, this.minute, this.second);
        }

        public int getHour()        //Essendo public posso richiamarla da altre classi
        {
            return this.hour;
        }

        public int getMinute()      //Essendo public posso richiamarla da altre classi 
        {
            return this.minute;
        }

        public double getSecond()   //Essendo public posso richiamarla da altre classi
        {
            return this.second;
        }

        public void setHour(int hour) 	//Essendo public posso richiamarla da altre classi
        {
            this.hour = hour;
             while (this.hour >= 24) 
                this.hour -= 24;
        }

        public void setMinute(int minute)   //Essendo public posso richiamarla da altre classi
        {
            this.minute = minute;
             while (this.minute >= 60) 
                this.minute -= 60;
        }

        public void setSecond(double second) 	//Essendo public posso richiamarla da altre classi
        {
            this.second = second;
            while (this.second >= 60.0)
                this.second -= 60.0;
        }

        public static Time add(Time t1, Time t2)  // Per richiamare la funzione Time endTime = Time.add(startTime, runningTime);
        {					  // Ritorna un nuovo oggetto tempo
            Time sum = new Time();
            sum.hour = t1.hour + t2.hour;
            sum.minute = t1.minute + t2.minute;
            sum.second = t1.second + t2.second;
            if (sum.second >= 60.0) 
            {
                sum.second -= 60.0;
                sum.minute += 1;
            }
            if (sum.minute >= 60)
            {
                sum.minute -= 60;
                sum.hour += 1;
            }
            return sum;
        }

        public void increment(double seconds)	 // Per richiamare la funzione tempo1.add(12.5);
        {               			 // Modifica (incrementa) l'oggetto sul quale è applicata
            this.second += seconds;
            while (this.second >= 60.0) 
            {
                this.second -= 60.0;
                this.minute += 1;
            }
            while (this.minute >= 60) 
            {
                this.minute -= 60;
                this.hour += 1;
            }
            while (this.hour >= 24) 
                this.hour -= 24;
        }

        public static void main(String[] args) 
        {
            Time time1 = new Time(23,59,59.9);
            time1.increment(3600);
            time1.printTime();
            time1.setSecond(90);
            time1.printTime();
            time1.setMinute(90);
            time1.printTime();
            time1.setHour(90);
            time1.printTime();
        }				

}
