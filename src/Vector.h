#pragma once

class Vector2
{
  private:
    double v[2];
  public:
    Vector2(void);
    Vector2(double x, double y);

    double& operator[](int index);
    double operator[](int index) const;
    Vector2 operator-(void) const;
    Vector2 operator+(const Vector2& u) const;
    Vector2& operator+=(const Vector2& u);
    Vector2 operator-(const Vector2& u) const;
    Vector2& operator-=(const Vector2& u);
    Vector2 operator*(double k) const;
    Vector2& operator*=(double k);
    Vector2 operator*(const Vector2& u) const;
    Vector2& operator*=(const Vector2& u);
    Vector2 operator/(double k) const;
    Vector2& operator/=(double k);
    Vector2 operator/(const Vector2& u) const;
    Vector2& operator/=(const Vector2& u);

    double length(void) const;
    Vector2 unit(void) const;
    double dot(const Vector2& u) const;
};

class Vector3
{
  private:
    double v[3];
  public:
    Vector3(void);
    Vector3(double x, double y, double z);

    double& operator[](int index);
    double operator[](int index) const;
    Vector3 operator-(void) const;
    Vector3 operator+(const Vector3& u) const;
    Vector3& operator+=(const Vector3& u);
    Vector3 operator-(const Vector3& u) const;
    Vector3& operator-=(const Vector3& u);
    Vector3 operator*(double k) const;
    Vector3& operator*=(double k);
    Vector3 operator*(const Vector3& u) const;
    Vector3& operator*=(const Vector3& u);
    Vector3 operator/(double k) const;
    Vector3& operator/=(double k);
    Vector3 operator/(const Vector3& u) const;
    Vector3& operator/=(const Vector3& u);

    double length(void) const;
    Vector3 unit(void) const;
    double dot(const Vector3& u) const;
    Vector3 cross(const Vector3& u) const;
};

