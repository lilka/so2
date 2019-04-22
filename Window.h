#include <vector>

class Window {
private:
    float height;
    float width;
public:
    Window();
    ~Window();

    void initWindow();
    float getHeight();
    float getWidth();
};
