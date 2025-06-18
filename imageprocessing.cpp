#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    string imagePath;
    cout << "Enter image path: ";
    cin >> imagePath;

    // Load image
    Mat image = imread(imagePath);
    if (image.empty()) {
        cout << "❌ Failed to load image." << endl;
        return -1;
    }

    // Display original image
    imshow("Original Image", image);

    // Convert to grayscale
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);
    imwrite("output_gray.jpg", gray);

    // Resize image
    Mat resized;
    resize(image, resized, Size(300, 300));
    imwrite("output_resized.jpg", resized);

    // Crop image
    Rect cropArea(50, 50, 200, 200);
    Mat cropped = image(cropArea);
    imwrite("output_cropped.jpg", cropped);

    // Apply blur filter
    Mat blurred;
    GaussianBlur(image, blurred, Size(7, 7), 0);
    imwrite("output_blurred.jpg", blurred);

    cout << "✅ Image processing completed. Check saved images.\n";

    waitKey(0);
    return 0;
}
