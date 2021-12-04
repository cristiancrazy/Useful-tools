/****************************************
 | Author: Cristian Capraro
 | Date: November 2021
 | Personal Project, under MIT LICENCE
 | 
 | Class: WinFrameGen (graphics gui)
 ****************************************/

package it.tools;


//IMPORT
import java.util.ArrayList;
import java.util.stream.*; //Stream API
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.BufferedWriter;


//CLASS
public class Tools {
	
	//EXPORT DATA ON FILE
	public static void resultWriter(String path, ArrayList<? extends Number> toExport, boolean append){
			
		try(BufferedWriter writer = new BufferedWriter(new FileWriter(new File(path), append));){
			ArrayList<String> results = new ArrayList<>(toExport.stream().map(i -> i.toString()).collect(Collectors.toList()));
				
			for(String s : results){
				writer.write(s.toString() + ";");
			}
			
			toExport.clear(); //Remove all elements
			
		}catch(IOException e){
			System.err.println("File I/O Error");
		}catch(Exception e){
			System.err.println("Error");
		};

	}


	public static void resultWriter(String path, ArrayList<? extends ArrayList<? extends Number>> toExport){
		for(var i : toExport){
			resultWriter(path, i, true);

			//Add new line on file
			try(BufferedWriter writer = new BufferedWriter(new FileWriter(new File(path), true))){
				writer.write('\n');
			}catch(IOException e){
				System.err.println("File I/O Error");
			}catch(Exception e){
				System.err.println("Error");
			}

		}
	}



	//ERASE DATA
	public static void resultErase(String path){
		
		try(BufferedWriter eraser = new BufferedWriter(new FileWriter(path, false))){
			eraser.write("");
		}catch(IOException e){
			System.err.println("File I/O Error");
		}catch(Exception e){
			System.err.println("Error");
		}

	}

}
