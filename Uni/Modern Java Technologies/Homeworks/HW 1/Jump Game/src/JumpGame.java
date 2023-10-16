public class JumpGame
{

	public static void main(String[] args)
	{
		int[] arr = {2, 1, 3, 0};
	}
	public static boolean canWin(int[] array){
		return canWinRecurs(array, 0);
	}

	static boolean canWinRecurs(int[] array, int current){
		if(current >= array.length - 1)
			return true;
		int steps = array[current];
		for(int i = 1; i <= steps; i++){
			if(canWinRecurs(array, current + i)){
				return true;
			}
		}
		return false;
	}
}
