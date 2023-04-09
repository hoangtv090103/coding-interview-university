public class Person {
    private String name;
    private String address;
    private int id;
    private int age;

    // Constructor
    public Person() // Empty constructor
    {

    }

    public Person(String name, String address, int id, int age) {
        this.name = name;
        this.address = address;
        this.id = id;
        this.age = age;
    }

    // Getter and Setter
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
