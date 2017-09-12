
class CopyArrayWhile {
	public static void main(String[] args){
		int[] array1 = { 7, 4, 8, 1, 4, 1, 4 };
		float[] array2 = new float[array1.length];
		
		// Print array1
		System.out.print("array1: [ ");
		for (int i = 0; i < array1.length; i ++){
			System.out.print(array1[i] + " ");
		}
		System.out.println("]");
		
		// Copy and print array2
//		System.out.print("array2: [ ");
//		int count = 0;
//		while ( count < array1.length && array1[count] != 1){
//			array2[count] = (float) array1[count];
//			System.out.print(array2[count++] + " ");
			
	//	}
//		System.out.println("]");
		
		// Skip elements "1" but continue copying everything else
//				System.out.print("array2 again: [ ");
				int count = 0;
				int count2 = 0;
				while ( count <= array1.length){
					if (array1[count] == 1){
						count ++;
						continue;
					}
						
					
					array2[count2] = (float) array1[count];
	//				System.out.print(array2[count2++] + " ");
					count++;
					count2++;
				} 
//				System.out.println("]");
		
	} // main
	
} // class
