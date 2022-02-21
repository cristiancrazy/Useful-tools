/* *******************************************
 * Author: Cristian Capraro
 * Date: February 2022
 * For personal purposes.
 * Under MIT Licence
 *
 * Little network tool - you could enter
 * an IPv4 and a Subnet mask, and It will
 * return the network's name and the standard
 * broadcast address.
 *
 * ===== OLD PROJECT UPDATE =================
 * This is an update of an old app that I
 * deployed (in the last December) using only
 * Java AWT. This wasn't a great idea.
 * So, I decided to rewrite it entirely with
 * JavaFX.
 * ==========================================
 *
 * *******************************************/

//Package and imports
package it.cristiancrazy.net.runner;


import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

import java.net.URL;

//Class
public class MainClass extends Application {
	//The Main method
	public static void main(String[] args){
		launch(args);
	}

	//Graphics loader

	@Override
	public void start(Stage primaryStage) throws Exception {
		//Setting up graphics
		URL graphics = Class.forName("it.cristiancrazy.net.graphics.GraphicsController").getResource("Graphics.fxml");
		Parent root = FXMLLoader.load(graphics);

		//Setting up scene and stage - Graphics Properties
		Scene scene = new Scene(root);

		primaryStage.setTitle("Net ip checker");
		primaryStage.setResizable(false);
		primaryStage.initStyle(StageStyle.UTILITY);

		primaryStage.setScene(scene);

		primaryStage.show();
	}
}
