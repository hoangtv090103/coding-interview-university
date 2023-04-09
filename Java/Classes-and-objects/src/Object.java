public class Object {
    public static void main(String[] args) {
        Person p = new Person();
        p.setId(1001);
        p.setName("Quynh");
        p.setAge(35);
        p.setAddress("Ninh Binh");
        System.out.println("Id: " + p.getId());
        System.out.println("Name: " + p.getName());
        System.out.println("Age: " + p.getAge());
        System.out.println("Address: " + p.getAddress());

        Person p1 = new Person("Quynh", "Ninh Binh", 1001, 35);

    }
}