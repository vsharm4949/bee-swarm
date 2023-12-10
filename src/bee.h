#ifndef __BEE_H__
#define __BEE_H__

struct Coordinate
{
    double x;
    double y;
};

class Bee {
public:
    explicit Bee(
        Role role,
        Coordinate position = { 0.0, 0.0 },
        Coordinate food = { 0.0, 0.0 },
        double buzz = 5.0
    ) : role(role), position(position), home(position), buzz(buzz), food(food)
    {
    }

    Role get_role() const { return role; }

    void communicate(Role new_role, Coordinate new_food);
    void scout(double x_move, double y_move);
    void work(double x_move, double y_move);
    void go_home();

    bool is_home() const {
        return (position.y > home.y - buzz)
            && (position.y < home.y + buzz)
            && (position.x > home.x - buzz)
            && (position.x < home.x + buzz)
    }

    void waggle(double jiggle);
    Coordinate get_pos() const { return position; }
    Coordinate get_food() const { return food; }

    void move_home(Coordinate new_home) {
        home = new_home;
    }

private:
    Role role;
    Coordinate position;
    Coordinate home;
    Coordinate food;
    const double buzz;
};


    

#endif
