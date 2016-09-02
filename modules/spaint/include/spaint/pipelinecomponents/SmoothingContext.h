/**
 * spaint: SmoothingContext.h
 * Copyright (c) Torr Vision Group, University of Oxford, 2016. All rights reserved.
 */

#ifndef H_SPAINT_SMOOTHINGCONTEXT
#define H_SPAINT_SMOOTHINGCONTEXT

#include "../util/ITMObjectPtrTypes.h"
#include "../util/LabelManager.h"
#include "../util/SpaintVoxelScene.h"

namespace spaint {

/**
 * \brief An instance of a class deriving from this one provides the shared context needed by a smoothing component.
 */
class SmoothingContext
{
  //#################### DESTRUCTOR ####################
public:
  /**
   * \brief Destroys the smoothing context.
   */
  virtual ~SmoothingContext() {}

  //#################### PUBLIC ABSTRACT MEMBER FUNCTIONS ####################
public:
  virtual const LabelManager_Ptr& get_label_manager() = 0;
  virtual const Settings_CPtr& get_settings() const = 0;
  virtual const SpaintVoxelScene_Ptr& get_voxel_scene(const std::string& sceneID) = 0;
};

//#################### TYPEDEFS ####################

typedef boost::shared_ptr<SmoothingContext> SmoothingContext_Ptr;

}

#endif