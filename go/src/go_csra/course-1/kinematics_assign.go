/*Let us assume the following formula for
displacement s as a function of time t, acceleration a, initial velocity Vo,
and initial displacement So.

s = ½ a t^2 + Vot + So

Write a program which first prompts the user
to enter values for acceleration, initial velocity, and initial displacement.
Then the program should prompt the user to enter a value for time and the
program should compute the displacement after the entered time.

You will need to define and use a function
called GenDisplaceFn() which takes three float64
arguments, acceleration a, initial velocity Vo, and initial
displacement So. GenDisplaceFn()
should return a function which computes displacement as a function of time,
assuming the given values acceleration, initial velocity, and initial
displacement. The function returned by GenDisplaceFn() should take one float64
argument t, representing time, and return one
float64 argument which is the displacement travelled after time t.

For example, let’s say that I want to assume
the following values for acceleration, initial velocity, and initial
displacement: a = 10, Vo = 2, So = 1. I can use the
following statement to call GenDisplaceFn() to
generate a function fn which will compute displacement as a function of time.

fn := GenDisplaceFn(10, 2, 1)

Then I can use the following statement to
print the displacement after 3 seconds.

fmt.Println(fn(3))

And I can use the following statement to print
the displacement after 5 seconds.

fmt.Println(fn(5))

*/
package main

import (
	"fmt"
	"math"
)

func GenDisplaceFn(a, Vo, So float64) func(float64) float64 {
	fn := func(t float64) float64 {
		return (a*math.Pow(t, 2))/2 + Vo*t + So
	}
	return fn
}

func main() {
	var accel, vel, dis, time float64
	fmt.Print("Enter Acceleration (a): ")
	fmt.Scan(&accel)
	fmt.Print("Enter Initial Velocity (Vo): ")
	fmt.Scan(&vel)
	fmt.Print("Enter Initial Displacement (So): ")
	fmt.Scan(&dis)
	fmt.Print("Enter Time (t): ")
	fmt.Scan(&time)
	displacement := GenDisplaceFn(accel, vel, dis)
	fmt.Println(displacement(time))
}
