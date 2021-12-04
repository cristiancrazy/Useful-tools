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

import java.util.Random; //Random N generator

//CLASS
public class Generator {
    

    //ArrayList number generator (long)
    public static ArrayList<Long> getDataLONG(long generateN, long min, long max, boolean positive_only){
        ArrayList<Long> output = new ArrayList<>();
        Random x = new Random();

        for(long i = 0; i < generateN; ++i)
        { 
            output.add( min + ( (positive_only)? Math.abs(x.nextLong()% (max+1-min)) : (x.nextLong()% (max+1-min)) ) ); //Filling
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
            output.add(min + ( (positive_only)? Math.abs(x.nextDouble() * ((min != 0)? (max/min) : max)) : (x.nextDouble() * ((min != 0)? (max/min) : max)) )); //Filling
        }
        
        System.gc(); //Suggest to use Garbage Collector
        
        return output;
    }


    //ArrayList matrix number generator (long)
    public static ArrayList<ArrayList<Long>> getMatrixLONG(long generateN, long min, long max, boolean positive_only){
        ArrayList<ArrayList<Long>> output = new ArrayList<>();

        for(int i = 0; i < generateN; ++i){
            output.add(getDataLONG(generateN, min, max, positive_only));
        }
        
        System.gc(); //Suggest to use Garbage Collector

        return output;
    }


    //ArrayList matrix number generator (double)
    public static ArrayList<ArrayList<Double>> getMatrixDOUBLE(long generateN, long min, long max, boolean positive_only){
        ArrayList<ArrayList<Double>> output = new ArrayList<>();

        for(int i = 0; i < generateN; ++i){
            output.add(getDataDOUBLE(generateN, min, max, positive_only));
        }
        
        System.gc(); //Suggest to use Garbage Collector

        return output;
    }


}