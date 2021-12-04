/****************************************
 | Author: Cristian Capraro
 | Date: November 2021
 | Personal Project, under MIT LICENCE
 |
 | This class contains methods
 | to generate results in different ways
 ****************************************/

package it.tools;


//IMPORT
import java.util.ArrayList;
import java.util.stream.*; //Stream API
import java.util.Random; //Random N generator

//CLASS
public class Generator {
    
    //ArrayList number generator (long)
    public static ArrayList<Long> getDataLONG(long generateN, long min, long max, boolean positive_only){
        ArrayList<Long> output = new ArrayList<>();
        Random x = new Random();

        for(long i = 0; i < generateN; ++i)
        { 
            output.add( min + (x.nextLong() % (max+1-min) ) ); //Filling
        }

        if(positive_only){
            LongStream outputabs = output.stream().mapToLong(i -> Math.abs(i));
            output.clear(); //Delete all items in the ArrayList
            outputabs.forEach(i -> output.add(i)); //Re-fill the ArrayList
        }
        
        System.gc(); //Suggest to use Garbage Collector

        return output;
    }

    //ArrayList number generator (double)
    public static ArrayList<Double> getDataDOUBLE(long generateN, long min, long max, boolean positive_only){
        ArrayList<Double> output = new ArrayList<>();
        Random x = new Random();

        for(long i = 0; i < generateN; ++i)
        { 
            output.add( min + (x.nextDouble() * ((min != 0)? (max/min) : max)) ); //Filling
        }

        if(positive_only){
            DoubleStream outputabs = output.stream().mapToDouble(i -> Math.abs(i));
            output.clear(); //Delete all items in the ArrayList
            outputabs.forEach(i -> output.add(i)); //Re-fill the ArrayList
        }
        
        System.gc(); //Suggest to use Garbage Collector
        
        return output;
    }

}
