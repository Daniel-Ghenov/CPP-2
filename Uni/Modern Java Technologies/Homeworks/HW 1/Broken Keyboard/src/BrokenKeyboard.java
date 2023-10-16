public class BrokenKeyboard
{
	public static int calculateFullyTypedWords(String message, String brokenKeys){
		String[] words = message.split(" ");
		char[] brokenKeysChars = brokenKeys.toCharArray();
		int wordsCount = 0;
		for(String word : words){
			if(word.trim().isEmpty())
				continue;
			if(canBeWrittenWith(word, brokenKeysChars))
				wordsCount++;
		}
		return wordsCount;
	}
	static boolean canBeWrittenWith(String word, char[] brokenKeysChars){
		for(char ch : word.toCharArray()){
			for(char broken : brokenKeysChars){
				if (ch == broken)
					return false;
			}
		}
		return true;
	}
}
