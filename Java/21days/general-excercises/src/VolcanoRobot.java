
public class VolcanoRobot {
	String status;
	int speed;
	float temperature;
	
	VolcanoRobot(String rstatus, int rspeed, int temp){
		status = rstatus;
		speed = rspeed;
		temperature = temp;
	}
	
	void checkTemperature(){
		if (temperature > 660){
			status = "returning home";
			speed = 5;			
		}
	}
	void showAttributes(){
		System.out.println("Status: " + status);
		System.out.println("Speed: " + speed);
		System.out.println("Temperature: " + temperature);
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
//		VolcanoRobot dante = new VolcanoRobot();
//		dante.status = "exploring";
//		dante.speed = 2;
//		dante.temperature = 510;
		VolcanoRobot dante = new VolcanoRobot("still exploring", 1, 300);

		dante.showAttributes();
		System.out.println("Increasing speed to 3.");
		dante.speed = 3;
		dante.showAttributes();
		System.out.println("Changing temperature to 670");
		dante.temperature = 670;
		dante.showAttributes();
		System.out.println("Checking the temperature");
		dante.checkTemperature();
		dante.showAttributes();
	}

}
