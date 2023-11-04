public class IPValidator
{

	public static void main(String[] args)
	{
		System.out.println(validateIPv4Address("0.0.168 .0"));
	}

	public static boolean validateIPv4Address(String str){

		String[] octets = str.split("\\.");

		if(octets.length != 4){
			return false;
		}
		for(String octet : octets){
			if(!isValidOctet(octet))
				return false;
		}
		return true;
	}

	static boolean isValidOctet(String octet){

		if(octet.isEmpty())
			return false;
		if(octet.length() != 1 && octet.charAt(0) == '0'){
			return false;
		}
		char[] chars = octet.toCharArray();
		for(char ch : chars){
			if(ch < '0' || ch >'9'){
				return false;
			}
		}

		int octetInt = Integer.parseInt(octet);
		if(octetInt < 0 || octetInt >= 256){
			return false;
		}
		return true;
	}

}