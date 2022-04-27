import java.util.*;
import java.io.*;

class Programm {
    public static void main(String[] args) throws IOException {
        FileInputStream ReadFile = new FileInputStream("text.txt");
        int length = ReadFile.available();
        byte[] data = new byte[length];
        ReadFile.read(data);
        String[] Substring = new String(data).split("\n");
        ArrayList<PhoneBook> people = new ArrayList<PhoneBook>();
        for(String txt : Substring) {
            String[] t = txt.trim().split(" ");
            PhoneBook abonent = new PhoneBook(t[0], t[1], t[2], t[3], t[4], Integer.parseInt(t[5]));
            abonent.PrintAbonent();
            people.add(abonent);
        }


      Collections.sort(people, new Comparator<PhoneBook>() {
            public int compare(PhoneBook FirstElement, PhoneBook SecondElement) {
                if (FirstElement.getAge() != SecondElement.getAge())
                    return FirstElement.getAge() - SecondElement.getAge();
                else
                    return FirstElement.getAge();
            }
        });
        System.out.println("Абоненты отсортированы по возрасту: \n");
        for(PhoneBook abonent : people) {
            abonent.PrintAbonent();
        }

        Collections.sort(people, new Comparator<PhoneBook>() {
            public int compare(PhoneBook FirstElement, PhoneBook SecondElement) {
                return FirstElement.getFIO().compareTo(SecondElement.getFIO());
            }
        });
        System.out.println("Абоненты отсортированы по ФИО: \n");
        for(PhoneBook abonent : people) {
            abonent.PrintAbonent();
        }


        Collections.sort(people, new Comparator<PhoneBook>() {
            public int compare(PhoneBook FirstElement, PhoneBook SecondElement) {
                return FirstElement.getHobby().compareTo(SecondElement.getHobby());
            }
        });
        System.out.println("Абоненты отсортированы по Хобби: \n");
        for(PhoneBook abonent : people) {
            abonent.PrintAbonent();
        }
    }
}

class PhoneBook {
    //поля
    private String FIO;
    private String JOB;
    private String MobPhone;
    private String HomePhone;
    private String Hobby;
    private int Age;

    //конструкторы
    public PhoneBook() {
        FIO = "";
        JOB = "";
        MobPhone = "";
        HomePhone = "";
        Hobby = "";
        Age = 0;
    }
    public PhoneBook(String FIO, String JOB, String MobPhone, String HomePhone, String Hobby, int Age) {
        this.FIO = FIO;
        this.JOB = JOB;
        this.MobPhone = MobPhone;
        this.HomePhone = HomePhone;
        this.Hobby = Hobby;
        this.Age = Age;
    }
    public PhoneBook(PhoneBook copy) {
        this.FIO = copy.FIO;
        this.JOB = copy.JOB;
        this.MobPhone = copy.MobPhone;
        this.HomePhone = copy.HomePhone;
        this.Hobby = copy.Hobby;
        this.Age = copy.Age;
    }

    public void PrintAbonent() { //
        System.out.println("FIO: " + FIO);
        System.out.println("JOB: " + JOB);
        System.out.println("MobPhone: " + MobPhone);
        System.out.println("HomePhone: " + HomePhone);
        System.out.println("Hobby: " + Hobby);
        System.out.println("Age: " + Age + '\n');
    }
    public String getFIO() {
        return FIO;
    }
    public String getJon() {
        return JOB;
    }
    public String getMobPPhone() {
        return MobPhone;
    }
    public String getHomePhone() {
        return HomePhone;
    }
    public String getHobby() {
        return Hobby;
    }
    public int getAge() {
        return Age;
    }
    public void setSize(int Age) {
        this.Age = Age;
    }
}