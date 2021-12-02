/****************************************
 | Author: Cristian Capraro
 | Date: November 2021
 | Personal Project, under MIT LICENCE
 | 
 | Class: WinFrameGen (FRAME CREATOR)
 ****************************************/

package it.graphics;


//IMPORT
import java.awt.*; //ABSTRACT WINDOW TOOLKIT
import java.awt.event.*;


//CLASS
public class WinFrameGen extends Frame{
    //enum

    public enum e_mode{ 
        EXIT, HIDE, DO_NOTHING
    }


    //constructor

    public WinFrameGen(String title, boolean resizable, int width, int height, e_mode exitmode){
        super(title); //Set title
        setSize(width, height);
        setLayout(null);
        setResizable(resizable); //Window resizable
        
        setExitMode(exitmode); //Set exit mode
    }


    //private methods
    
    private void setExitMode(e_mode mode){
        //Exit program
        if(mode == e_mode.EXIT){
            addWindowListener(new WindowAdapter(){
                @Override
                public void windowClosing(WindowEvent e){
                    System.exit(0); //End application
                }
            });
        }
        
        //Hide window
        else if(mode == e_mode.HIDE){
            addWindowListener(new WindowAdapter(){
                @Override
                public void windowClosing(WindowEvent e){
                    dispose(); //Release all resources
                }
            });
        }
    }


    //public methods
    

    public void setColor(Color background, Color foreground){ //Set window default color
        setForeground(foreground);
        setBackground(background);
    }


    public void addMultipleComponents(Component ...component){ //Add multiple component
        for(var i : component)
            add(i);
    }

    /***********************************************
     * With this static method you're allowed to
     * create new MenuBar or update an already
     * defined MenuBar (boolean UPDATE parameter).
     ***********************************************/
    public static WinFrameGen addMenuBar(boolean update, WinFrameGen frame, String menuName, String[] itemsName, ActionListener[] actions){
        
        //Require the same length
        if(itemsName.length == actions.length){
            
            //Menubar
            MenuBar bar = (update)? frame.getMenuBar() : new MenuBar();
            
            //New Menu and items
            Menu menu = new Menu(menuName);
            MenuItem[] items = new MenuItem[itemsName.length]; 

            for(int i = 0; i < items.length; ++i){
                items[i] = new MenuItem(itemsName[i]);
                items[i].addActionListener(actions[i]);
                menu.add(items[i]); 
            }
            bar.add(menu);

            frame.setMenuBar(bar);
        }

        return frame;
    }

}
