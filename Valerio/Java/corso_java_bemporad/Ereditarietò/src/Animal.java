public class Animal {
    private String species, envoirment, sound, name;
    private int legs, wings, fins;
    Animal(String name, String species, int legs, int wings, int fins, String envoirment, String sound) {
        this.species = species;
        this.envoirment = envoirment;
        this.sound = sound;
        this.legs = legs;
        this.wings = wings;
        this.fins = fins;
        this.name = name;
    }

    private String capital(String s) {
        return s.substring(0,1).toUpperCase().concat(s.substring(1));
    }

    void info() {
        class Obj {
            String name, feature;
            int value;
            Obj(String name, int value) {
                this.name = capital(name);
                this.value = value;
                this.feature = "";
            }
            Obj(String feature, String name) {
                this.feature = capital(feature);
                this.name = name;
                this.value = 0;
            }
        }

        Obj[] a = {
                new Obj("name", name),
                new Obj("species", species),
                new Obj("envoirment",envoirment),
                new Obj("sound", sound),
                new Obj("legs", legs),
                new Obj("wings", wings),
                new Obj("fins", fins)
        };

        for (Obj o: a) {
            if (o.value != 0 || !o.feature.equals("")) {
                System.out.print((!o.feature.equals("") ? o.feature : o.name) + ": ");
                System.out.println(o.value != 0 ? o.value : o.name);
            }
        }
    }
}
