package candriai.stanze.java;

public interface StanzeIterator {
	boolean hasNext();
	boolean hasNextBig();
	Object next();
	Object nextBig();
	
	boolean hasPrev();
	Object prev();
	
	boolean set(Object element);
	boolean del();
}
