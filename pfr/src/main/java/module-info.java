module com.example.pfr {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens com.example.pfr to javafx.fxml;
    exports com.example.pfr;
    exports com.example.pfr.controleur.vueGraphique;
    opens com.example.pfr.controleur.vueGraphique to javafx.fxml;
}