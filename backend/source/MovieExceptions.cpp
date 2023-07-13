#include "MovieExceptions.h"


namespace mv::exc
{
	std::exception

		ModelNotCreated("Model object not created yet!"),
		cantOpenInputVideo("Can\'t open input video!"),
		invalidFramePos("Invalid frame position!"),
		emptyTemplate("Template img is empty!"),
		invalidSegm("Segment is\'t varible (first < second)!"),


		outOfRange("Out of range!"),
		emptyImage("Image is empty!"),
		cantOpenVideo("Cant\'t open video source!"),


		cantFindInputVideo("Can\'t find input video!"),
		cantFindOutputDir("Can\'t find output folder!"),
		cantFindTemplImg("Can\'t find template image!"),

		invalidPointPosX("Search point width out of range!"),
		invalidPointPosY("Search point height out of range!"),

		bigSearchArea("Search area more then reservó search point!"),
		lessSearchArea("Search area less then template image!"),

		bigStep("Step of frames more? then video size!"),
		invalidThreshold("Threshold out of range (0; 1)!"),

		invalidThreadsCount("Threads count is large!"),


		invalidPos("Start or end position is\'t valid!"),
		emptyList("List is empty!"),

		cantFindObserver("Can\'t find observer!"),
		nullPointer("Pointer is null!"),
		invalidJson("Json document is damaged!");
}