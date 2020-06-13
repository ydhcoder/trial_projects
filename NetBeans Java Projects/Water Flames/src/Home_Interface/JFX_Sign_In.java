package Home_Interface;

import java.awt.event.MouseEvent;
import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

/**
 *
 * @author Yeabsra Debebe
 */
public class JFX_Sign_In extends Application {
    
    private double xOffset = 0;
    private double yOffset = 0;
    
    @Override
    public void start(Stage primaryStage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("Home.fxml"));
        primaryStage.initStyle(StageStyle.TRANSPARENT);
        
        root.setOnMousePressed(new EventHandler<MouseEvent>() {
            
            @Override
            public void handle(MouseEvent evt) {
                xOffset = evt.getSceneX();
                yOffset = evt.getSceneY();
            }
        });  
        
        root.setOnMouseDragged(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent evt) {
                primaryStage.set(evt.getScreenX - xOffset);
                primaryStage.set(evt.getScreenY - xOffset);
            }
        });
        
    }
    public static void main(String[] args) {
        launch(args);
    }
    
}
