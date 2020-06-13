package Home_Interface;

import java.io.IOException;
import javafx.event.ActionEvent;
import java.net.URL;
import java.util.ResourceBundle;
import static javafx.application.Application.launch;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;
 
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @autor Yeabsra Debebe
 */
public class HomeController implements Initializable {

    private Button btn_signIn, btn_signUp;
    private AnchorPane an_signIn, an_signUp;

    public HomeController() throws IOException {
        this.root = FXMLLoader.load(getClass().getResource("Home.fxml"));
    }
    
    public void handleButtonAction(ActionEvent evt) {
        if(evt.getSource() == btn_signIn)
        {
            an_signIn.toFront();
        }
        else if(evt.getSource() == btn_signUp) {
            an_signUp.toFront();
        }
    }
    
    Parent root;
   
    public void start(Stage stage) throws Exception {
        
    }
    
   
    
    @Override
    public void initialize(URL utr, ResourceBundle rb) { 
    }
    
    public static void main (String[] args) {
        launch(args);
    }
    
    
}
    
