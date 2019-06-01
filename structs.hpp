
struct coord {
    int x;
    int y;

    inline bool operator==(const struct coord& rhs) {
        return (this->x == rhs.x && this->y == rhs.y);
    }

    inline struct coord operator+(const struct coord& rhs) {
        struct coord sumCoord;
        sumCoord.x = this->x + rhs.x;
        sumCoord.y = this->y + rhs.y;
        return sumCoord;
    }
};
