#pragma once
#include <exception>

namespace mv::exc
{
	extern std::exception

		ModelNotCreated,
		cantOpenInputVideo,
		invalidFramePos,
		invalidSegm,

		emptyTemplate,
		emptyImage,
		cantOpenVideo,


		cantFindInputVideo,
		cantFindOutputDir,
		cantFindTemplImg,

		invalidPointPosX,
		invalidPointPosY,

		bigSearchArea,
		lessSearchArea,

		bigStep,
		invalidThreshold,

		invalidThreadsCount,


		invalidPos,
		outOfRange,
		emptyList,

		cantFindObserver,
		nullPointer,
		invalidJson;
}