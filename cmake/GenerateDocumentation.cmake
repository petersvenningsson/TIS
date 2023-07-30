add_custom_target(doc COMMAND
	              doxygen
				  ${CMAKE_CURRENT_SOURCE_DIR}/doc/doxygen_cfg
				  )
