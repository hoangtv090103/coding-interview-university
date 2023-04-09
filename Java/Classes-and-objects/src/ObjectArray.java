public class ObjectArray {
    public static void main(String[] args) {
        Student[] students = new Student[30];
        for (int i = 0; i < 30; i++) {
            // Khởi tạo các phần tử trong mảng students
            students[i] = new Student();
        }

        Student[] students1 = new Student[3];
        students1[0] = new Student("Thai", 12);
        students1[1] = new Student("Tuan", 13);
        students1[2] = new Student("Duc", 11);

        for (int i = 0; i < 3; i++) {
            students1[i].display();
        }
    }
}
