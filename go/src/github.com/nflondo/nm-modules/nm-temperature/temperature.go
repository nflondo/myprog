package temperature

type Temperature float64

func CtoF(c float64) Temperature {
	return Temperature((c * 9 / 5) + 32)
}

func FtoC(f float64) Temperature {
	return Temperature((f - 32) * 5 / 9)
}

// Formula to convert celsius to Kelvins  T (K) = T (°C) + 273.15.
func CtoK(c float64) Temperature {
	return Temperature(c + 273.15)
}
