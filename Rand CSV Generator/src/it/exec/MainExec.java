/****************************************
 | Author: Cristian Capraro
 | Date: November 2021
 | Personal Project, under MIT LICENCE
 | 
 | This application allows you to create
 | and export vectors/matrices on a CSV
 | file.
 |
 | This class contains the MAIN method
 ****************************************/

package it.exec;


//IMPORT
import java.awt.*;
import java.awt.event.ActionListener;


import it.graphics.*;
import it.graphics.WinFrameGen.e_mode;
import it.tools.*;
import it.tools.GeneratorSettings.genMode;


//CLASS
public class MainExec{

    //App Version
    public static String app_update = "MID DEC21";

    
    private static WinFrameGen WindowMAIN(){ //GUI SETUP [WINDOW "MAIN"]
        //GUI SETUP
        WinFrameGen mainFrame = new WinFrameGen("vcmt rand", false, 300, 300, e_mode.EXIT);
        mainFrame.setColor(Color.black, Color.red);
        
        /* =========== [COMPONENTS] =========== */
        
        //Checkbox
        CheckboxGroup SelectionMode = new CheckboxGroup();

        Checkbox[] Selection = new Checkbox[]{
            new Checkbox("INTEGER"),    //0
            new Checkbox("DOUBLE"),     //1
            new Checkbox("INT MATRIX"),
            new Checkbox("DOUBLE MATRIX")
        };


        int h_chkbox = 50; //Set size
        for(Checkbox i : Selection){
            i.setLocation(25,(h_chkbox+=25));
            i.setSize(120, 20);
            i.setCheckboxGroup(SelectionMode);
        }
        
        Checkbox Erase = new Checkbox("OVERWRITE");
        Erase.setBounds(145, 75, 100, 20);
        Erase.setForeground(Color.YELLOW);
        
        //TextBox
        Label num_label = new Label("Number of Elements: ");
        num_label.setBounds(20, 180, 120, 25);
                
        TextField num_field = new TextField(null);
        num_field.setBounds(20, 205, 120, 25);
        
        //Submit button
        Button submitButton = new Button("Validate");
        submitButton.setBackground(Color.BLACK);
        submitButton.setForeground(Color.GREEN);
        submitButton.setBounds(145, 205, 80, 25);
        
        //Info label
        Label res_label = new Label();
        res_label.setBounds(20, 255, 120, 25);
        res_label.setForeground(Color.BLUE);
        res_label.setBackground(Color.BLACK);

        //Execute action
        submitButton.addActionListener(i ->{
            //Remove the past feedback
            try{
                res_label.setText("");
                Thread.sleep(100); //Delay
            }catch(InterruptedException e){ };
            


            //Feedback string
            String feedback = "";
            
            //Set mode
            genMode mode = genMode.NOTHING;
            long value;

            if(Selection[0].getState()) //INTEGER
                mode = genMode.INTEGER_VECTOR;
            if(Selection[1].getState()) //DOUBLE
                mode = genMode.DOUBLE_VECTOR;
            if(Selection[2].getState()) //INTEGER MATRIX
                mode = genMode.INTEGER_2MATRIX;
            if(Selection[3].getState()) //DOUBLE MATRIX
                mode = genMode.DOUBLE_2MATRIX;
            
            try{
                if(mode == genMode.NOTHING) throw new Exception("INVALID MODE");

                value = Long.parseLong(num_field.getText());
                
                if(value > GeneratorSettings.getMaximumLimit()) 
                    throw new Exception("MAX LIMIT: "+GeneratorSettings.getMaximumLimit());
                
                GeneratorSettings.setElementsN(value, mode, Erase.getState());
                
                timeinfo time = new timeinfo(); //Record time
                feedback = GeneratorSettings.ComputeFunctionality(); // <-- The heart 
                
                feedback += (" - " + time); //End record time

            }catch(NumberFormatException e){
                feedback = "INVALID FORMAT";
            }catch(Exception e){
                feedback = e.getMessage();
            }

            res_label.setText(feedback);
        }); 

        //Adding all these components to the frame
        mainFrame.addMultipleComponents(Selection);
        mainFrame.addMultipleComponents(Erase, num_label, num_field, res_label, submitButton);

        System.gc(); //Suggest to execute Garbage Collection

        return mainFrame;
    }

    private static WinFrameGen WindowABOUT(){ //GUI SETUP [WINDOW "ABOUT"]
        
        WinFrameGen aboutFrame = new WinFrameGen("About", false, 250, 250, e_mode.HIDE);
        aboutFrame.setColor(Color.BLACK, Color.RED); //Set frame colors
        
        /* =========== [COMPONENTS] =========== */
        
        //Label
        Label info[] = new Label[6];
        info[0] = new Label("Written by Cristian Capraro.");
        info[0].setForeground(new Color(0xFF, 0xFF, 0xFF)); //Set Text Color

        info[1] = new Label("[Under MIT Licence]");
        info[1].setForeground(Color.YELLOW); //Set Text Color

        info[2] = new Label("Version: " + app_update);

        info[3] = new Label("Utility app: generate and");
        info[3].setForeground(Color.GREEN); //Set Text Color

        info[4] = new Label("export random values on a .csv file.");
        info[4].setForeground(Color.GREEN); //Set Text Color
        
        info[5] = new Label("github.com/cristiancrazy");
        info[5].setFont(new Font("Arial", Font.BOLD, 12));
        info[5].setForeground(Color.WHITE); //Set Text Color
        
        int h_infoLbl = 60;  //Start label height
        for(Label i : info){ //Placing on Frame
            i.setBounds(25, h_infoLbl, 200, 25);
            i.setAlignment(Label.CENTER);
            h_infoLbl += 25; //Increment height for next label
        }
        aboutFrame.addMultipleComponents(info);


        return aboutFrame;
    }

    private static WinFrameGen WindowSETTINGS(){ //GUI SETUP [WINDOW "SETTINGS"]

        WinFrameGen settingsFrame = new WinFrameGen("Settings", false, 260, 300, e_mode.HIDE);
        settingsFrame.setColor(Color.BLACK, Color.RED); //Set frame colors
        
        /* =========== [COMPONENTS] =========== */

        //Label
        Label title_label = new Label("Settings:");
        title_label.setFont(new Font("Arial", Font.BOLD, 16));
        title_label.setBounds(0, 35, 250, 25);
        title_label.setAlignment(Label.CENTER);

        Label[] setVal_label = new Label[]{
            new Label("WORK FILE: "),
            new Label("MIN VALUE: "),
            new Label("MAX VALUE: "),
            new Label("SEPARATOR: ")
        };
        int hVal = 50;
        for(Label i : setVal_label){
            i.setBounds(25, (hVal+=35), 80, 25);
        }

        //TextFields
        TextField[] setVal_fields = new TextField[]{
            new TextField("results.csv"),
            new TextField("0"),
            new TextField("500")
        };

        hVal = 50;
        for(TextField i : setVal_fields){
            i.setBounds(120, (hVal+=35), 100, 25);
            
        }

        //Radio checkbox (separator)
        CheckboxGroup separatorType = new CheckboxGroup();
        
        Checkbox separator1 = new Checkbox(";", separatorType, true);
        separator1.setForeground(Color.WHITE);
        separator1.setFont(new Font("Arial", Font.PLAIN, 16));
        separator1.setBounds(120, 188, 25, 25);

        Checkbox separator2 = new Checkbox(",", separatorType, false);
        separator2.setForeground(Color.WHITE);
        separator2.setFont(new Font("Arial", Font.PLAIN, 16));
        separator2.setBounds(160, 188, 25, 25);
        
        //Radio (positive only)
        Checkbox positive = new Checkbox();
        positive.setBounds(120, 223, 25, 25);

        Label positive_label = new Label("ONLY +");
        positive_label.setBounds(25, 223, 75, 25);


        //Validate options button - Feedback label
        Button validate = new Button("Set");
        validate.setBounds(25, 258, 60, 25);
        validate.setForeground(Color.YELLOW);
        validate.setBackground(Color.BLACK);

        Label feedback_label = new Label("");
        feedback_label.setBounds(100, 258, 120, 25);
        feedback_label.setForeground(Color.BLUE);
        feedback_label.setBackground(Color.BLACK);

        //Action - set
        validate.addActionListener(l -> {
            String feedback = "OK";

            //Checks
            try{
                if( !(setVal_fields[0].getText().matches("[a-zA-Z0-9]{1,}[\\.][c][s][v]")) ) //Path check
                    throw new Exception("INVALID FILE");

                //Check range number
                if( !(setVal_fields[1].getText().matches("\\d{1,}")) )
                    throw new Exception("INVALID MIN");

                if( !(setVal_fields[2].getText().matches("\\d{1,}")) )
                    throw new Exception("INVALID MAX");



                //Range validation
                String path = setVal_fields[0].getText();
                long min = Long.parseLong(setVal_fields[1].getText());
                long max = Long.parseLong(setVal_fields[2].getText()); 

                if(min > max){ // max must be greater than min
                    throw new Exception("RANGE ERROR");
                }


                //Set data
                
                char separator = (separator1.getState())? separator1.getLabel().charAt(0) : separator2.getLabel().charAt(0);
                Tools.setSeparator(separator);

                GeneratorSettings.setSettings(path, min, max, positive.getState());



            }catch(Exception e){
                feedback = e.getMessage();
            }

            feedback_label.setText(feedback);
            
            //Delay - Feedback remove
            try{
                Thread.sleep(2500); 
                feedback_label.setText("");
            }catch(InterruptedException e){ } 

        });

        settingsFrame.addMultipleComponents(title_label, separator1, separator2, positive, positive_label, validate, feedback_label);
        settingsFrame.addMultipleComponents(setVal_label);
        settingsFrame.addMultipleComponents(setVal_fields);

        return settingsFrame; 
    }


    //MAIN METHOD
    public static void main(String[] args){
        //FRAMES
        WinFrameGen mainFrame = WindowMAIN();
        WinFrameGen aboutFrame = WindowABOUT();
        WinFrameGen settingsFrame = WindowSETTINGS();

        //MENU BAR
        mainFrame = WinFrameGen.addMenuBar(false, mainFrame, "Config", 
                    new String[]{"Settings", "Exit"}, new ActionListener[]{i -> settingsFrame.setVisible(true), i -> System.exit(0)});

        mainFrame = WinFrameGen.addMenuBar(true, mainFrame, "?", 
                    new String[]{"About"}, new ActionListener[]{i -> aboutFrame.setVisible(true)});
            
        mainFrame.setVisible(true);

    }
}