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
package it.cristiancrazy.net.graphics;

import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import javafx.scene.control.TextField;


import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

//Class
public class GraphicsController {
	//Label IPv4 and Subnet Mask
	@FXML
	public TextField IPv4Box;

	@FXML
	public TextField MaskBox;
	//Check Button
	@FXML
	public void CheckButton() {
		String outNetName, outBroadcast;

		boolean checkIP = IPv4Box.getText().matches("[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}");
		boolean checkMask = MaskBox.getText().matches("[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}");

		//Valid
		if(checkIP&&checkMask){
			//Transform to number
			List<Integer> IPv4 = Arrays.stream((IPv4Box.getText().split("\\."))).map(Integer::parseInt).toList();
			List<Integer> MASK = Arrays.stream((MaskBox.getText().split("\\."))).map(Integer::parseInt).toList();

			//Check range
			if(IPv4.stream().anyMatch(value -> !((value<=255)&&(value>=0)) ) || (MASK.stream().anyMatch(value -> !((value<=255)&&(value>=0)) ))){
				outBroadcast = "Invalid";
				outNetName = "Invalid";
			}else{
				Integer[] OUT_NET_IP = new Integer[4];
				Integer[] OUT_NET_BROADCAST = new Integer[4];

				/* ======== MOST IMPORTANT PART OF THIS PROJECT ======== */

				for(int x = 0; x < IPv4.size(); ++x){
					OUT_NET_IP[x] = IPv4.get(x)&MASK.get(x); //IP and MASK (net ip)
					OUT_NET_BROADCAST[x] = ((~MASK.get(x)&0xFF)|IPv4.get(x)); //Inverted mask or ip (broadcast ip)
				}

				/* ===================================================== */

				//Transform to String
				outNetName = Arrays.stream(OUT_NET_IP).map(integer -> Integer.toString(integer)).collect(Collectors.joining("."));
				outBroadcast = Arrays.stream(OUT_NET_BROADCAST).map(integer -> Integer.toString(integer)).collect(Collectors.joining("."));

			}
		}else{
			outBroadcast = "Invalid";
			outNetName = "Invalid";
		}

		//Show alert
		Alert showResult = new Alert(Alert.AlertType.NONE,
				"Network IP = "+outNetName+"\nBroadcast IP = "+outBroadcast, ButtonType.OK);
		showResult.setTitle("IPs Results");
		showResult.showAndWait();

	}
}
