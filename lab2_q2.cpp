// C++ Program to calculate area of square, cube, rectangle, and cuboid using classes
#include <cstdio>

// Class definitions
class Square {
    private:
    int length;
    public:
        Square()  
            {length = 1;}
            void setlen(int);
            int calculateArea() {
                return length * length;
            }

}objsq;

class Cube {
public:
    Cube(int side) : length(side) {}
    int calculateArea() {
        return 6 * length * length;
    }
    void display() {
        printf("Cube Surface Area: %d\n", calculateArea());
    }
public:
    int length;
};

class Rectangle {
public:
    Rectangle(int l, int w) : length(l), width(w) {}
    int calculateArea() {
        return length * width;
    }
    void display() {
        printf("Rectangle Area: %d\n", calculateArea());
    }
public:
    int length;
    int width;
};

class Cuboid {
public:
    Cuboid(int l, int w, int h) : length(l), width(w), height(h) {}
    int calculateArea() {
        return 2 * (length * width + length * height + width * height);
    }
    void display() {
        printf("Cuboid Surface Area: %d\n", calculateArea());
    }
public:
    int length;
    int width;
    int height;
};

// Main function
int main() {
    int choice;
    while (choice <= 4) {
        printf("\nGeometry Calculator\n");
        printf(" 1. Square\n 2. Cube\n 3. Rectangle\n 4. Cuboid\n 5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int side;
                printf("Enter the side length of the square: ");
                scanf("%d", &side);
                objsq.setlen(side);
                printf("the area of the square is:%d",objsq.calculateArea());
                break;
            // }
            // case 2: {
            //     int side;
            //     printf("Enter the side length of the cube: ");
            //     scanf("%d", &side);
            //     Cube cube(side);
            //     cube.display();
            //     break;
            // }
            // case 3: {
            //     int length, width;
            //     printf("Enter the length of the rectangle: ");
            //     scanf("%d", &length);
            //     printf("Enter the width of the rectangle: ");
            //     scanf("%d", &width);
            //     Rectangle rectangle(length, width);
            //     rectangle.display();
            //     break;
            // }
            // case 4: {
            //     int length, width, height;
            //     printf("Enter the length of the cuboid: ");
            //     scanf("%d", &length);
            //     printf("Enter the width of the cuboid: ");
            //     scanf("%d", &width);
            //     printf("Enter the height of the cuboid: ");
            //     scanf("%d", &height);
            //     Cuboid cuboid(length, width, height);
            //     cuboid.display();
            //     break;
            // }
            // case 5:
            //     printf("Exiting the program. Goodbye!\n");
            //     break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    }

    return 0;
}
void Square::setlen(int temp){
    length = temp;
}