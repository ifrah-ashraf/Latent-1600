package gradleproj ;
import java.awt.Desktop ;
import java.net.URI ;

public class App {
    public static void main(String[] args){
        try {
            String url = "https://www.google.com" ;
            if (Desktop.isDesktopSupported()){
                Desktop desktop = Desktop.getDesktop();
                desktop.browse(new URI(url));
            }else {
                System.out.println("Desktop not supported");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
