import java.io.IOException;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;

class SmartBulbDimmable extends SmartDevice {
    private double lightIntensity = .5;
    private double totalConsumo = 0;

    public SmartDevice (String id, double consumoPorHora) {
        super(id,consumoPorHora);
    }

    public consumoPorHora() {return consumoPorHora * lightIntensity;}

    @Override
    public totalConsumo() {return totalConsumo;}

    @Override
    public void turnOff() {
        this.on = false;
        long timeOn = Duration.between(this.inicio,LocalDateTime.now()).toHours();
        this.inicio == null;
        this.totalConsumo += timeOn * consumoPorHora();
    }


    private static class InvalidLightIntensity extends Exception {};
    public void changeLightIntensity (double newLightIntesity) {
        if (!(newLightIntesity >= 0 && newLightIntesity <= 1)) throw new InvalidLightIntensity();
        long timeOn = Duration.between(this.inicio,LocalDateTime.now()).toHours();
        inicio == LocalDateTime.now();
        totalConsumo += timeOn * consumoPorHora();
        lightIntensity = newLightIntesity;
    }
}



public void alteraInfo(Consumer<SmartBulbDimmable> bd) {
    this.devices()
        .filter(v->v instanceof SmartBulbDimmable)
        .map(v-> (SmartBulbDimmable)v)
        .forEach(bd);
    bd = s -> s.changeLightIntensity(.25);
}


public boolean apenasNumaDivisao() {
    return this.devices
                    .stream()
                    .distinct()
                    .count()
                    ==
           this.divisionDevices
                    .values()
                    .stream()
                    .map(Collection::size)
                    .reduce(0, Integer::sum);

}


public boolean gravaEmFichObjectos(String fich) throws FileNotFoundException, IOException{
    ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream(fich));
    this.devices.stream().filter(sd -> sd instanceof SmartSpeaker).forEach(o -> os.writeObject(o));
    os.flush();
    os.close();
    return true;
}