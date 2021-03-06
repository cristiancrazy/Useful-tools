/****************************************
 | Author: Cristian Capraro
 | Date: November 2021
 | Personal Project, under MIT LICENCE
 | 
 | This application allows you to create
 | and export vectors/matrices on a CSV
 | file.
 |
 | This class contains Generator's export
 | settings.
 |
 | ComputeFunctionality is here!!!!
 ****************************************/
package it.tools;

//IMPORT
import java.io.Serializable; //To export settings

//CLASS
public class GeneratorSettings implements Serializable{
    //Instance Variables

    
    /***************************************************
     * This constant represents the highest number of
     * elements (INTEGER) that can be generated by this
     * application (single validation).
     **************************************************/
    private final static long maxValueGenerated = Short.MAX_VALUE;
    

    /* [Default settings - Startup Config] */


    private static long elementsN = 0; //Number of elements to generate
    private static String path = "results.csv"; //Export filename
    private static long min = 0; //Range generator (min)
    private static long max = 500; //Range generator (max)
    private static boolean positive_only = false; //Export only + values
    private static boolean overwrite = false; //Overwrite file
    private static genMode mode; //Type of output requested by user


    //enum (generation mode)
   
   
    public enum genMode{
        INTEGER_VECTOR, DOUBLE_VECTOR, INTEGER_2MATRIX, DOUBLE_2MATRIX, NOTHING
    }


    //working methods

    /*************************************
    * The heart of this application is
    * here.
    * Use this method with static 
    * variables [GeneratorSettings Class]
    *************************************/
    public static String ComputeFunctionality(){
        String diagnostic = "";

        //Erase output on request
        if(overwrite) Tools.resultErase(path);


        //Mode
        switch(mode){
            case INTEGER_VECTOR:
                Tools.resultWriter(path, Generator.getDataLONG(elementsN, min, max, positive_only), true);
                diagnostic = "OK (" + elementsN + ")";
            break;
            case INTEGER_2MATRIX:
                Tools.resultWriter(path, Generator.getMatrixLONG(elementsN, min, max, positive_only));
                diagnostic = "OK (" + elementsN + ")";
            break;
            case DOUBLE_VECTOR:
                Tools.resultWriter(path, Generator.getDataDOUBLE(elementsN, min, max, positive_only), true);
                diagnostic = "OK (" + elementsN + ")";
            break;
            case DOUBLE_2MATRIX:
                Tools.resultWriter(path, Generator.getMatrixDOUBLE(elementsN, min, max, positive_only));
                diagnostic = "OK (" + elementsN + ")";
            break;
            case NOTHING:
                diagnostic = "KO - NO MODE";
        }


        return diagnostic;
    }


    //methods
    
    
    public static void setElementsN(long N, genMode M){
        elementsN = N;
        mode = M;
    }


    public static void setElementsN(long N, genMode M, boolean overwriteFile){
        elementsN = N;
        mode = M;
        overwrite = overwriteFile;
    }

    
    public static void setSettings(String newPath, long newMin, long newMax, boolean newPositive_only){
        path = newPath;
        min = newMin;
        max = newMax;
        positive_only = newPositive_only;
    }


    public static String getPath(){
        return path;
    }


    public static long getMin(){
        return min;
    }


    public static long getMax(){
        return max;
    }


    public static boolean getPositive_only(){
        return positive_only;
    }


    public static long getElementsN(){
        return elementsN;
    }


    /***************************************************
     * The highest number of elements 
     * (INTEGER) that can be generated by this
     * application on a single time.
     * 
     * The highest number for DOUBLE option is
     * (maxValueGenerated)/2
     **************************************************/
    public static long getMaximumLimit(){
        return maxValueGenerated;
    }


}
