/****************************************
 * Author: Cristian Capraro
 * Date: December 2021
 * This class includes methods to measure
 * time (generic purposes)  
 * Personal Project, under MIT LICENCE
 ****************************************/

package it.tools;


//IMPORT
import java.time.LocalTime;
import java.time.Duration;


public class timeinfo {
    //INSTANCE VARIABLES
    private LocalTime t_start, t_stop;


    //CONSTRUCTOR
    public timeinfo(){
        t_start = LocalTime.now(); //Time start
    }


    //METHODS
    public void reset_timeinfo(){
        t_start = LocalTime.now();
    }


    //RETURN TIME
    @Override
    public String toString(){ //Print time difference (t_stop-t_start)
        t_stop = LocalTime.now(); //Time end
        return "" + ((Duration.between(t_start, t_stop).toSeconds() > 60)? (Duration.between(t_start, t_stop).toMinutes() + " mins"): Duration.between(t_start, t_stop).toSeconds() + " secs");
    }


}
